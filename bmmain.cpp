#include <iostream>
#include "boyermoore.hpp"
#include "string.h"

int main(){
    char p[]="bat";
    char t[]="tabataraabatara";

    BoyerMoore bm(std::span(p,strlen(p)));
    auto result=bm.search(std::span(t,strlen(t)));
    std::cout <<result << std::endl;
}