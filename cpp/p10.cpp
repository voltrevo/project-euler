#include <iostream>
using namespace std;

#include "primeFeed.hpp"
#include "gmpxx.h"

typedef mpz_class mpz;

int main()
{
    PrimeFeed pf;
    
    mpz sum = 0;
    int p = pf.Next();
    while (p < 2000000)
    {
        sum += p;
        p = pf.Next();
    }
    
    cout << sum << endl;
    
    return 0;
}
