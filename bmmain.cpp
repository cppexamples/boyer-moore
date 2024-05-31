#include <iostream>
#include "boyermoore.hpp"

int main(){
    BoyerMoore bm((char *)"bat");
    auto result=bm.search((char *)"tarataraabatara");
    std::cout <<result << std::endl;
}