#include "boyermoore.hpp"
#include "iostream"
#include "string.h"

BoyerMoore::BoyerMoore(char *pat, char *txt) : mpat{pat}, mtxt{txt}
{
    m = strlen(mpat);
    n = strlen(mtxt);
    make_d0();
    make_d1();
    s = mtxt + m - 1;
    endtxt = mtxt + n;       
    std::cout << mpat << std::endl;
    std::cout << mtxt << std::endl;
    std::cout << "012345678901234567890" << std::endl;
    std::cout << "          1         2" << std::endl;
};

// see Fast String Seaching by andrew hume and daniel sanday
void BoyerMoore::make_d0()
{
    for (int i = 0; i < LENGTH_OF_ALPHABET; i++)
        d0[i] = m;

    for (int j = 0; j < m ; j++){
        d0[int(*(mpat + j))] = m-j-1;       
    }    
}

void BoyerMoore::make_d1()
{

    for (int i = 0; i < LENGTH_OF_ALPHABET; i++)
    {
        d1[i] = -1;
    }

    for (int j = 0; j < m; j++)
    {
        d1[int(*(mpat + j))] = j;
    }
}

// see Fast String Seaching by andrew hume and daniel sanday
void BoyerMoore::ufast()
{    
    int k = 0;
    while (true){
        k = d0[int(*(s+=k))];                
        if(k==0 || endtxt<s) break;
    }    
}

size_t BoyerMoore::search()
{    

    int skip = 0;
    while (s < endtxt)
    {        
        ufast();        
        skip = 0;
        for (int j = m - 1 - 1; j >= 0; j--) // mpat[m-1] already in function ufast tested
        {
            if (mpat[j] != *(s - (m - j-1)))
            {
                skip = j - d1[int(*(s - (m - j-1)))];
                if (skip < 1)
                    skip = 1;
                break;
            }
        }
        if (skip == 0)
        {
            return size_t(s-mtxt-m+1);
        }
        s+=skip;
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
