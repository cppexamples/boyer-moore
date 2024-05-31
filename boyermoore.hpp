#pragma once
#include <string>
#include <span>

const int LENGTH_OF_ALPHABET = 256;

class BoyerMoore
{

public:
    int d1[LENGTH_OF_ALPHABET];
    int d0[LENGTH_OF_ALPHABET];
    BoyerMoore(std::span<char> p);
    size_t search(std::span<char> t);
    void make_d0();
    void make_d1();
    void ufast();
    void printhead();
    std::span<char> pat;
    std::span<char> txt;
    size_t s;    
    size_t m;
    size_t n;
};