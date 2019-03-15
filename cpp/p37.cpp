#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int RemoveFirstDigit(int x)
{
    int tenPow = 1;
    while (tenPow <= x)
        tenPow *= 10;
    
    tenPow /= 10;
    
    return x - (x / tenPow * tenPow);
}

int main()
{
    PrimeFeed pf;
    
    int count = 0;
    int sum = 0;
    
    int x = pf.Next();
    while (x < 10)
        x = pf.Next();
    
    while (count != 11)
    {
        bool couldBe = true;
        int xx = x / 10;
        while (xx != 0 && couldBe)
        {
            couldBe = pf.CheckPrime(xx);
            xx /= 10;
        }
        
        xx = RemoveFirstDigit(x);
        while (xx != 0 && couldBe)
        {
            couldBe = pf.CheckPrime(xx);
            xx = RemoveFirstDigit(xx);
        }
        
        if (couldBe)
        {
            sum += x;
            ++count;
        }
        
        x = pf.Next();
    }
    
    cout << sum << endl;
    
    return 0;
}
