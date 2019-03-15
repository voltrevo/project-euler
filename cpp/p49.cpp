#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

#include "primeFeed.hpp"

bool UnorderedStringComparison(const char* a, const char* b)
{
    multiset<char> aChars;
    multiset<char> bChars;
    
    int i;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; ++i)
    {
        aChars.insert(a[i]);
        bChars.insert(b[i]);
    }
    
    return a[i] == b[i] && aChars == bChars;
}

char* IntToString(int x)
{
    double xd = x + 0.5;
    int digitCount = 0;
    while (xd >= 1)
    {
        xd /= 10;
        ++digitCount;
    }
    
    char* s = new char[digitCount + 1];
    s[digitCount] = '\0';
    
    for (int i = 0; i != digitCount; ++i)
    {
        xd *= 10;
        s[i] = '0' + static_cast<int>(xd);
        xd -= floor(xd);
    }
    
    return s;
}

int main()
{
    PrimeFeed pf;
    
    for (int i = 1000; i != 9999; ++i)
    {
        if (!pf.CheckPrime(i))
            continue;
        
        char* s = IntToString(i);
        while (next_permutation(s, s + 4))
        {
            int j = atoi(s);
            int k = 2 * j - i;
            
            if (pf.CheckPrime(j) && pf.CheckPrime(k) && k <= 10000 &&
                UnorderedStringComparison(s, IntToString(k)))
            {
                cout << i << j << k << endl;
            }
        }
        
        delete [] s;
    }
    
    return 0;
}
