#include "boyermoore.hpp"
#include "iostream"
#include "string.h"

BoyerMoore::BoyerMoore(char* pat): mpat{pat}{
    
    for(int i=0;i<LENGTH_OF_ALPHABET;i++){
        d1[i]=-1;
    }

    size_t m=strlen(mpat);
    for(int j=0;j<m;j++){
        d1[int(*(mpat+j))]=j;
    }

};
void BoyerMoore::print() {
    std::cout<< mpat << std::endl;    
    size_t m=strlen(mpat);
    for(auto j=mpat;j<mpat+m;j++){
        std::cout<<(char)*(j) <<" " << d1[(int)*j] << std::endl;
    }
}
