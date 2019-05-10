// -----------------------------------------------------------------------------
//
// Copyright (C) The BioDynaMo Project.
// All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// See the LICENSE file distributed with this work for details.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership.
//
// -----------------------------------------------------------------------------
#ifndef PYRAMIDAL_CELL_H_
#define PYRAMIDAL_CELL_H_

#include "biodynamo.h"
#include "biology-modules.h"
#include "core/substance_initializers.h"
#include "my-neurite.h"
#include "neuroscience/neuroscience.h"
#include <iostream>
#include <fstream>

namespace bdm {

using namespace std;

// Define compile time parameter
BDM_CTPARAM(experimental::neuroscience) {
  BDM_CTPARAM_HEADER(experimental::neuroscience);

  using NeuriteElement = MyNeurite;

  using SimObjectTypes =
      CTList<experimental::neuroscience::NeuronSoma, bdm::MyNeurite>;

  BDM_CTPARAM_FOR(bdm, MyNeurite) {
    using BiologyModules = CTList<ApicalElongationBM, BasalElongationBM>;
  };
};

struct NeuronBuilder {
  void operator()(const std::array<double, 3>& position) {
    auto* rm = Simulation<>::GetActive()->GetResourceManager();

    experimental::neuroscience::NeuronSoma soma(position);
    soma.SetDiameter(10);
    auto soma_soptr = soma.GetSoPtr();
    rm->push_back(soma);

    auto&& dendrite_apical = soma_soptr->ExtendNewNeurite({0, 0, 1});
    dendrite_apical->AddBiologyModule(ApicalElongationBM());
    dendrite_apical->SetCanBranch(true);

    
  }
};

/// define substance for neurite attraction
inline void DefineSubstances(const Param* param) {
  ModelInitializer::DefineSubstance(kSubstanceApical, "substance_apical", 0, 0,
                                    param->max_bound_ / 2);
  ModelInitializer::DefineSubstance(kSubstanceBasal, "substance_basal", 0, 0,
                                    param->max_bound_ / 2);
  // create substance with gaussian distribution for neurite attraction
  ModelInitializer::InitializeSubstance(
      kSubstanceApical, GaussianBand(param->max_bound_, 200, Axis::kZAxis));
  ModelInitializer::InitializeSubstance(
      kSubstanceBasal, GaussianBand(param->min_bound_, 200, Axis::kZAxis));
}

inline int Simulate(int argc, const char** argv) {
  Simulation<> simulation(argc, argv);

#pragma omp parallel
  simulation.GetRandom()->SetSeed(8794);
  simulation.GetExecutionContext()->DisableNeighborGuard();

  NeuronBuilder builder;
  builder({0, 0, 0});
  DefineSubstances(simulation.GetParam());

	/*//File 
	template<typename TSimulation = Simulation<>>
	inline void neuron_morphology_export(int i){
	
	int seed = TSimulation::GetActive()->GetRandom()->GetSeed();
	auto* param = TSimulation::GetActive()->GetParam();
	*/

	ofstream Neuron_Morphology;
	stringstream NM_header;
	NM_header << "Neuron_Morphology.txt";

	std::string file_name_neuron_morphology = NM_header.str();
	Neuron_Morphology.open(file_name_neuron_morphology);
		
	

	for(int i = 0; i<=100; i++){

	
	  simulation.GetScheduler()->Simulate(1);

	auto* rm = Simulation<>::GetActive()->GetResourceManager();
	auto test_neuron = rm->template Get<MyNeurite>();
	if(test_neuron->GetDaughterRight() == nullptr){
		cout<<"Right Daughter"<<endl;		
		}
	if(test_neuron->GetDaughterLeft() != nullptr){
		cout<<"left Daughter"<<endl;		
		}
	
	auto dia = test_neuron->GetDiameter();
	auto position = test_neuron->GetPosition();
	cout<< "Diameter is: "<< dia << endl;
	cout<< "X: "<< position[0]<<" "<<"Y: "<<position[1]<<" "<<"Z:"<< position[2]<< endl;
	cout<<"Entering into swc file"<<endl;
	Neuron_Morphology<<i<<" "<<dia<<" "<<position[0]<<" "<<position[1]<<" "<<position[2]<<" "<<"1"<<endl;
	
}
  std::cout << "Simulation completed successfully!" << std::endl;
	Neuron_Morphology.close();
  return 0;
}

}  // namespace bdm

#endif  // PYRAMIDAL_CELL_H_
