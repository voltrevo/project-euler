#include <cassert>
#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int ProperDivisorSum(int x)
{
    if (x == 1 || x == 0)
        return 0;
    
    static PrimeFeed pf;
    pf.Restart();
    
    list<int> factors;
    factors.push_back(1);
    
    while (x != 1)
    {
        int p = pf.Next();
        int pCount = 0;
        while (x % p == 0)
        {
            x /= p;
            ++pCount;
        }
        
        int sz = factors.size();
        list<int>::iterator it = factors.begin();
        for (int i = 0; i != sz; ++i)
        {
            int pPow = p;
            for (int j = 0; j != pCount; ++j)
            {
                factors.push_back(*it * pPow);
                pPow *= p;
            }
            
            ++it;
        }
    }
    
    factors.pop_back();
    
    int sum = 0;
    for (list<int>::iterator it = factors.begin(); it != factors.end(); ++it)
        sum += *it;
    
    return sum;
}

bool Amicable(int x)
{
    int y = ProperDivisorSum(x);
    return x != y && ProperDivisorSum(y) == x;
}

int main()
{
    assert(6 == ProperDivisorSum(6));
    assert(28 == ProperDivisorSum(28));
    assert(Amicable(220));
    assert(Amicable(284));
    
    int sum = 0;
    
    for (int i = 1; i != 10000; ++i)
    {
        if (Amicable(i))
            sum += i;
    }
    
    cout << sum << endl;
    
    return 0;
}
