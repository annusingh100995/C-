#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

bool is_greater_than_5(int value){

        return(value > 5);
    }

    void run_withi_for_each(std::function<void (int)> func){
        vector<int> numbers {1,2,3,4,5,6,7,8,9,10,20,30,40,50};

    for_each(numbers.begin(), numbers.end(),func);

    }

int main()
{
    int t = 0;
    auto func1 = [](int y){cout << y<< endl;};
    auto func2 = [&t](int z){ t = z *3 ; cout<< t<< endl;};



run_withi_for_each(func1);
run_withi_for_each(func2);

}


