#include <iostream>

#include "../polynomial/powBySqr.h"

#include "gmpxx.h"

mpz_class DigitSum(mpz_class n)
{
    mpz_class sum = 0;
    
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    
    return sum;
}

int main()
{
    mpz_class max = 0;
    
    for (mpz_class a = 1; a != 100; ++a)
    {
        for (int b = 1; b != 100; ++b)
        {
            mpz_class sum = DigitSum(PowBySqr(a, b));
            if (sum > max)
            {
                max = sum;
                //std::cout << a << " ^ " << b << ": " << sum << std::endl;
            }
        }
    }
    
    std::cout << max << std::endl;
    
    return 0;
}
