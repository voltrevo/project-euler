#include <cassert>
#include <deque>
#include <iostream>
#include <list>

#include "gmpxx.h"

#include "boost/lexical_cast.hpp"

#include "primeTester.hpp"

bool IsPrime(int n)
{
    static PrimeTester pt(100u * 1000u * 1000u);
    return pt(n);
    
    /*
    mpz_class mpn = n;
    int result = mpz_probab_prime_p(mpn.get_mpz_t(), 5);
    return (result != 0);
    */
    /*
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
    */
}

bool ValidateLast(const std::list<int>& primeIndices, const std::deque<int>& primes)
{
    std::string lastPrime = boost::lexical_cast<std::string>(primes[primeIndices.back()]);
    
    for (std::list<int>::const_iterator it = primeIndices.begin(); it != primeIndices.end(); ++it)
    {
        if (*it == primeIndices.back())
        {
            ++it;
            assert(it == primeIndices.end());
            break;
        }
        
        std::string pStr = boost::lexical_cast<std::string>(primes[*it]);
        
        if (!IsPrime(boost::lexical_cast<int>(lastPrime + pStr)))
            return false;
        
        if (!IsPrime(boost::lexical_cast<int>(pStr + lastPrime)))
            return false;
    }
    
    return true;
}

int main()
{
    const int PRIME_LIMIT = 10000;
    
    std::deque<int> primes;
    for (int i = 2; i != PRIME_LIMIT; ++i)
    {
        if (IsPrime(i))
            primes.push_back(i);
    }
    
    std::list<std::list<int> > primeGroups;
    std::list<std::list<int> > primeGroupsBuf;
    for (int i = 0; i != primes.size(); ++i)
    {
        primeGroups.push_back(std::list<int>());
        primeGroups.back().push_back(i);
    }
    
    for (int length = 1; length != 5; ++length)
    {
        std::swap(primeGroups, primeGroupsBuf);
        primeGroups.clear();
        
        for (
            std::list<std::list<int> >::iterator it = primeGroupsBuf.begin();
            it != primeGroupsBuf.end();
            ++it)
        {
            for (it->push_back(it->back() + 1); it->back() != primes.size(); ++it->back())
            {
                if (ValidateLast(*it, primes))
                    primeGroups.push_back(*it);
            }
        }
        
        if (length > 2)
        {
            for (
                std::list<std::list<int> >::iterator it = primeGroups.begin();
                it != primeGroups.end();
                ++it)
            {
                for (std::list<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
                    std::cout << primes[*jt] << ' ';
                
                std::cout << std::endl;
            }
        }
    }
    
    return 0;
}
