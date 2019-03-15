#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int NumFactors(int x)
{
    static PrimeFeed pf;
    
    pf.Restart();
    
    int factorCount = 1;
    
    while (x != 1)
    {
        int p = pf.Next();
        int count = 0;
        while (x % p == 0)
        {
            x /= p;
            ++count;
        }
        
        factorCount *= count + 1;
    }
    
    return factorCount;
}

int main()
{
    int triNum = 0;
    int factorCount = 0;
    int i = 1;
    while (factorCount <= 500)
    {
        triNum += i;
        
        factorCount = NumFactors(triNum);
        
        ++i;
    }
    
    cout << triNum << endl;
    
    return 0;
}
