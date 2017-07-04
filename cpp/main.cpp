#include "./demo_lib.h"
#include <vector>
#include <ctime>

bool charArrayToInt(char* in, int &out){
    out = 0;
    int c;
    for (char* p=in; *p!= '\0'; p++){
        c = *p - '0';
        if (c<0 || c>9)
            return false;
        out*=10;
        out+=c;
    }
    return true;   
}

int main(int argc, char* args[]){
    // check number of input
    if (argc !=2){
        std::cout<<"error input"<< std::endl;
        return 0;
    }
    Demo_lib demo = Demo_lib();
    int limit;
    // convert from char array to number
    if (!charArrayToInt(args[1],limit)){
        std::cout<<"input is not a positive integer" << std::endl;
        return 0;
    }
    std::vector<int> out;
    clock_t begin = clock();
    demo.getPrimUnder(limit,out);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    // print output
    std::cout<<"There are " << out.size() << " primes under "<< limit << "." << std::endl;
    std::cout<<elapsed_secs << " sec are used for calculation"<< std::endl;
    return 0;
}