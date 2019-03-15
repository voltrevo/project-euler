#include <cstdlib>
#include <iostream>
using namespace std;

#include "gmpxx.h"

typedef mpz_class mpz;

mpz PowBySqr(mpz x, int n)
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

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;
    
    mpz val = PowBySqr(2, atoi(argv[1]));
    
    mpz sum = 0;
    
    while (val != 0)
    {
        sum += val % 10;
        val /= 10;
    }
    
    cout << sum << endl;
    
    return 0;
}
