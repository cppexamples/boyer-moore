#include <iostream>
#include "boyermoore.hpp"

int main(){
    BoyerMoore bm((char *)"bat",(char *)"tabataraabatara");
    auto result=bm.search();
    std::cout <<result << std::endl;
}