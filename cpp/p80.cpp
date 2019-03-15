#include <cassert>
#include <iostream>

#include "gmpxx.h"

int main()
{
    int s = 2;
    
    mpz_class twoHundredZeros = 1;
    for (int i = 0; i != 200; ++i)
        twoHundredZeros *= 10;
    
    mpz_class sum = 0;
    
    for (int i = 2; i != 100; ++i)
    {
        if (i == s * s)
        {
            ++s;
            continue;
        }
        
        mpz_class sqRoot = sqrt(i * twoHundredZeros);
        
        sqRoot /= 10;
        
        for (int j = 0; j != 100; ++j)
        {
            sum += (sqRoot % 10);
            sqRoot /= 10;
        }
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}
