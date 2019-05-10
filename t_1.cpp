#include <cstdlib>
#include <iostream>
#include <string>
 
int main() {
     
    // Create a string
    std::string sQuestion ("Enter Number 1 : ");
    
    // Create empty strings to store values
    std::string sNum1, sNum2;
    
    std::cout << sQuestion;
    
    // Receive user input and store it
    getline(std::cin, sNum1);
    
    std::cout << "Enter Number 2 : ";
    getline(std::cin, sNum2);
    
    // Convert from strings to int
    // std::stod converts from strings to doubles
    int nNum1 = std::stoi(sNum1);
    int nNum2 = std::stoi(sNum2);
    
    // Math Operators
    printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
    printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
    printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
    printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
    printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2));
    
    // ----- PROBLEM : MILES TO KILOMETERS -----
    // Sample knowing that kilometers = miles * 1.60934
    // Enter Miles : 5
    // 5 miles equals 8.0467 kilometers
    
    // Create needed variables
    std::string sMiles;
    double dMiles, dKilometers;
    
    // Ask user to input miles and store string input
    std::cout << "Enter Miles : ";
    getline(std::cin, sMiles);
    
    // Convert from string to double
    dMiles = std::stod(sMiles);
    
    // Convert from miles to km
    dKilometers = dMiles * 1.60934;
    
    // Output the results
    printf("%.1f miles equals %.4f kilometers\n", dMiles, dKilometers);
    
    // ----- END PROBLEM : MILES TO KILOMETERS -----
    
    return 0;
}
