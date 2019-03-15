#include <cstdlib>
#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int main()
{
    PrimeFeed pf;
    
    int lastPrime = 0;
    
    while (lastPrime < 100)
    {
        if (rand() % 2 == 0)
        {
            while (!pf.CheckPrime(++lastPrime));
            cout << lastPrime << endl;
        }
        else
        {
            int p = pf.Next();
            while (p <= lastPrime)
                p = pf.Next();
            
            lastPrime = p;
            
            cout << lastPrime << endl;
        }
    }
    
    return 0;
}
