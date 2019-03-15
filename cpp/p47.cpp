#include <iostream>
using namespace std;

#include "primeFeed.hpp"

bool FourPrimeFactors(int x)
{
    static PrimeFeed pf;
    pf.Restart();
    
    int pCount = 0;
    while (x != 1)
    {
        int p = pf.Next();
        
        if (x % p == 0)
        {
            ++pCount;
            if (pCount > 4)
                return false;
            
            x /= p;
        }
        
        while (x % p == 0)
            x /= p;
    }
    
    return pCount == 4;
}

int main()
{
    int i = 1;
    int count = 0;
    while (count != 4)
        count = (FourPrimeFactors(i++) ? count + 1 : 0);
    
    cout << i - 4 << endl;
    
    return 0;
}
