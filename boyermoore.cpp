#include "boyermoore.hpp"
#include "iostream"

BoyerMoore::BoyerMoore(std::span<char> p)
{    
    m = p.size();
    pat = p;    
    make_d0();
    make_d1();    
};

// see Fast String Seaching by andrew hume and daniel sanday
void BoyerMoore::make_d0()
{    
    for (int i = 0; i < LENGTH_OF_ALPHABET; i++)
        d0[i] = m;

    for (int j = 0; j < m; j++)
    {
        d0[int(pat[j])] = m - j - 1;        
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
        d1[int(pat[j])] = j;
    }    
}

// see Fast String Seaching pdf by andrew hume and daniel sanday
void BoyerMoore::ufast()
{    
    int k = 0;
    do {
        k = d0[int(txt[s += k])];        
    } while(k!=0 && s< n);
}

size_t BoyerMoore::search(std::span<char> t)
{
    n = t.size();
    txt = t;

    printhead();

    int skip = 0;
    s=m-1;
    while (s < n)
    {
        ufast();
        skip = 0;
        for (int j = m - 1 - 1; j >= 0; j--) // mpat[m-1] already in function ufast tested
        {
            if (pat[j] != txt[s - (m - j - 1)])
            {
                skip = j - d1[int(txt[s - (m - j - 1)])];
                if (skip < 1)
                    skip = 1;
                break;
            }
        }
        if (skip == 0)
        {
            return size_t(s - m + 1);
        }
        s += skip;
    }
    return n;
}

void BoyerMoore::printhead()
{
   // std::cout << pat.data() << std::endl;
   // std::cout << txt.data() << std::endl;
   // std::cout << "012345678901234567890" << std::endl;
   // std::cout << "          1         2" << std::endl;    
}
