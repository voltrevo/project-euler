#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "gmpxx.h"
#include "primeFeed.hpp"

typedef mpz_class mpz;

int main()
{
    PrimeFeed pf;
    char digits[] = "0123456789";
    
    mpz sum = 0;
    
    do
    {
        pf.Restart();
        int i = 1;
        bool couldBe = true;
        while (couldBe && i != 8)
        {
            swap(digits[i + 3], digits[10]);
            
            couldBe = atoi(&digits[i]) % pf.Next() == 0;
            
            swap(digits[i + 3], digits[10]);
            ++i;
        }
        
        if (couldBe)
        {
            cout << atoi(digits) << " == " << digits << endl;
            sum += atoi(digits);
        }
    }
    while (next_permutation(digits, digits + 10));
    
    cout << sum << endl;
    
    return 0;
}
