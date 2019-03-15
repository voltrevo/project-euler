#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int main()
{
    PrimeFeed pf;
    pf.Next(); // Skip 2;
    pf.Next(); // Skip 3;
    pf.Next(); // Skip 5;
    pf.Next(); // Skip 7;
    int p = pf.Next(); // 11
    int np = 7;
    
    bool expressable = true;
    
    while (expressable)
    {
        np += 2;
        
        if (np == p)
        {
            p = pf.Next();
            continue;
        }
        
        expressable = false;
        int s = 1;
        while (!expressable && 2 * s * s < np)
        {
            if (pf.CheckPrime(np - 2 * s * s))
                expressable = true;
            else
                ++s;
        }
    }
    
    cout << np << endl;
    
    return 0;
}
