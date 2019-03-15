#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int Rotate(int x)
{
    int last = x % 10;
    x /= 10;
    
    int tenPow = 1;
    while (tenPow <= x)
        tenPow *= 10;
    
    return last * tenPow + x;
}

int main()
{
    PrimeFeed pf;
    
    int count = 0;
    for (int p = pf.Next(); p < 1000000; p = pf.Next())
    {
        int r = Rotate(p);
        bool couldBeCircular = true;
        while (r != p && couldBeCircular)
        {
            couldBeCircular = pf.CheckPrime(r);
            r = Rotate(r);
        }
        
        if (couldBeCircular)
            ++count;
    }
    
    cout << count << endl;
    
    return 0;
}
