#include <cassert>
#include <iostream>
#include <list>

#include "boost/cstdint.hpp"

#include "primeTester.hpp"

std::list<int> primes;

int Totient(int n)
{
    int nCopy = n;
    int result = n;
    std::list<int>::iterator p = primes.begin();
    while (nCopy > 1)
    {
        assert(p != primes.end());
        assert(*p <= n);
        if (nCopy % *p == 0)
        {
            result = result / *p * (*p - 1);
            nCopy /= *p;
            while (nCopy % *p == 0)
                nCopy /= *p;
        }
        
        ++p;
    }
    
    return result;
}

int main()
{
    PrimeTester pt(1000000);
    
    for (int i = 2; i != 1000000; ++i)
    {
        if (pt(i))
            primes.push_back(i);
    }
    
    boost::uint64_t sum = 0;
    
    for (int i = 2; i != 1000001; ++i)
    {
        if (i % 100000 == 0)
            std::cout << i << std::endl;
        
        sum += Totient(i);
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}
