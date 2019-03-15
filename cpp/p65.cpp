#include <algorithm>
#include <cassert>
#include <iostream>

#include "gmpxx.h"

mpz_class GCD(mpz_class a, mpz_class b)
{
    while (std::min(a, b) != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    
    return std::max(a, b);
}

mpq_class GetEApprox(int t)
{
    mpq_class q = 0;
    
    for (int i = t; i > 1; --i)
    {
        if (i % 3 == 0)
            q += 2 * i / 3;
        else
            q += 1;
        
        q = 1 / q;
    }
    
    q += 2;
    
    q.canonicalize();
    return q;
}

int main()
{
    mpq_class q = GetEApprox(100);
    assert(GCD(q.get_num(), q.get_den()) == 1);
    
    mpz_class numerator = q.get_num();
    
    mpz_class digitSum = 0;
    while (numerator > 0)
    {
        digitSum += (numerator % 10);
        numerator /= 10;
    }
    
    std::cout << digitSum << std::endl;
    
    return 0;
}
