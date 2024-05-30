#pragma once
#include <string>
const int LENGTH_OF_ALPHABET=256;

class BoyerMoore
{


public:
int d1[LENGTH_OF_ALPHABET];
    BoyerMoore(char* pat);
    void print();
    char* mpat;
};