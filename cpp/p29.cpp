#include <iostream>
#include <set>
using namespace std;

#include "gmpxx.h"

typedef mpz_class mpz;

mpz PowBySqr(mpz x, mpz n)
{
    mpz result = 1;
    
    while (n != 0)
    {
        if (n % 2 == 0)
        {
            x *= x;
            n /= 2;
        }
        else
        {
            result *= x;
            --n;
        }
    }
    
    return result;
}

int main()
{
    set<mpz> vals;
    
    for (mpz a = 2; a != 101; ++a)
        for (mpz b = 2; b != 101; ++b)
            vals.insert(PowBySqr(a, b));
    
    cout << vals.size() << endl;
    
    return 0;
}
