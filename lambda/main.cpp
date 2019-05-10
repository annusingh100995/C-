#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

void add_some(int *i){(*i) += 3;}
void add_some(double *x){(*x) *= 10;}



int main()
{

  int a(1);
  double b(1.23);

  add_some(&a);
  add_some(&b);

  cout<< "a = "<< a << endl << "b = "<< b << endl;

}

