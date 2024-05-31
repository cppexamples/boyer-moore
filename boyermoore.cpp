#include "boyermoore.hpp"
#include "iostream"
#include "string.h"

BoyerMoore::BoyerMoore(char *pat) : mpat{pat}
{

    for (int i = 0; i < LENGTH_OF_ALPHABET; i++)
    {
        d1[i] = -1;
    }

    size_t m = strlen(mpat);
    for (int j = 0; j < m; j++)
    {
        d1[int(*(mpat + j))] = j;
    }
};

size_t BoyerMoore::search(char *txt)
{
    std::cout << mpat << std::endl;
    std::cout << txt << std::endl;
    std::cout << "012345678901234567890" << std::endl;
    std::cout << "          1         2" << std::endl;

    size_t n = strlen(txt);
    size_t m = strlen(mpat);
    int skip;
    for (int i = 0; i <= n - m; i += skip)
    {
        skip = 0;
        for (int j = m - 1; j >=0; j--)
        {
            if (mpat[j] != txt[i + j])
            {
                skip = j - d1[int(txt[i + j])];
                if (skip < 1)
                    skip = 1;
                break;
            }
        }
        if (skip == 0)
        {
            return i;
        }
    }
    return n;
}

void BoyerMoore::print()
{
    std::cout << mpat << std::endl;
    size_t m = strlen(mpat);
    for (auto j = mpat; j < mpat + m; j++)
    {
        std::cout << (char)*(j) << " " << d1[(int)*j] << std::endl;
    }
}
