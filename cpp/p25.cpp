#include <iostream>
using namespace std;

#include "gmpxx.h"

typedef mpz_class mpz;

int main()
{
    mpz first1000DigitNum = 1;
    for (int i = 0; i != 999; ++i)
        first1000DigitNum *= 10;
    
    mpz fib[2] = {1, 1};
    int fibIndex = 0;
    
    int i = 2;
    while (fib[fibIndex] < first1000DigitNum)
    {
        fibIndex = !fibIndex;
        fib[fibIndex] += fib[!fibIndex];
        ++i;
    }
    
    cout << i << endl;
    
    return 0;
}
