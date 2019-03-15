#include <iostream>
using namespace std;

#include "gmpxx.h"

typedef mpz_class mpz;

int main()
{
    mpz x = 1;
    for (int i = 2; i != 101; ++i)
        x *= i;
    
    mpz sum = 0;
    
    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    
    cout << sum << endl;
    
    return 0;
}
