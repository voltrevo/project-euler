#include <iostream>

#include "gmpxx.h"

int NumDigits(mpz_class n)
{
    int digits = 0;
    
    while (n > 0)
    {
        ++digits;
        n /= 10;
    }
    
    return digits;
}

int main()
{
    mpz_class a = 1;
    mpz_class b = 1;
    
    int posCases = 0;
    
    for (int i = 0; i != 1000; ++i)
    {
        a += 2 * b;
        b = a - b;
        
        if (NumDigits(a) > NumDigits(b))
            ++posCases;
    }
    
    std::cout << posCases << std::endl;
    
    return 0;
}
