#include <iostream>
#include <list>
#include <set>
using namespace std;

#include "primeFeed.cpp"

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

bool Abundant(int x)
{
    return ProperDivisorSum(x) > x;
}

int main()
{
    list<int> abundants;
    set<int> sum2Abundants;
    
    for (int i = 1; i != 28123; ++i)
        if (Abundant(i))
            abundants.push_back(i);
    
    for (list<int>::iterator i = abundants.begin(); i != abundants.end(); ++i)
        for (list<int>::iterator j = i; j != abundants.end() && *i + *j < 28123; ++j)
            sum2Abundants.insert(*i + *j);
    
    int non2Abundants = 1;
    int sum = 0;
    for (set<int>::iterator i = sum2Abundants.begin(); i != sum2Abundants.end(); ++i)
    {
        while (non2Abundants < *i)
            sum += non2Abundants++;
        
        ++non2Abundants;
    }
    
    cout << sum << endl;
    
    return 0;
}
