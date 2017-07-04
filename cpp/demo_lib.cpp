#include "./demo_lib.h"
#include <algorithm>

void Demo_lib::getPrimUnder(const int limit,std::vector<int> &out)const {
    out.clear();    
    // fill with true
    bool* prime = new bool[limit];    
    std::fill_n(prime,limit,true);
    // find all non-prime
    for (int i = 2; i < limit; i++){
        if (!prime[i-1]) continue; //not prime
        //set all mults to false
        int mult = 2;
        while(i*mult <= limit){
            prime[i*mult-1] = false;
            mult++;
        }
    }
    //fill output vector
    for (int i=0; i< limit; i++)
        if (prime[i]) out.push_back(i+1);
    delete[] prime;
}
