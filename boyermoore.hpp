#pragma once
#include <string>
const int LENGTH_OF_ALPHABET = 256;

class BoyerMoore
{

public:
    int d1[LENGTH_OF_ALPHABET];
    int d0[LENGTH_OF_ALPHABET];
    BoyerMoore(char *pat, char *txt);
    size_t search();
    void make_d0();
    void make_d1();
    void ufast();
    void print();
    char *mpat;
    char *mtxt;
    char *s;
    char *endtxt;    
    size_t m;
    size_t n;
};