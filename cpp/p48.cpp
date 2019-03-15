#include <iostream>
using namespace std;

#include "gmpxx.h"

typedef mpz_class mpz;

mpz PowBySqrModulo(mpz x, mpz n, mpz mod)
{
    mpz result = 1;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            x = (x * x) % mod;
            n /= 2;
        }
        else
        {
            result = (result * x) % mod;
            --n;
        }
    }
    
    return result;
}

int main()
{
    mpz sum = 0;
    mpz mod("10000000000");
    for (int i = 1; i != 1001; ++i)
        sum = (sum + PowBySqrModulo(i, i, mod)) % mod;
    
    cout << sum << endl;
    
    return 0;
}
