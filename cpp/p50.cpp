#include <deque>
#include <iostream>

#include "primeFeed.hpp"

const std::size_t LIMIT = 1000000u;

int main()
{
    PrimeFeed pf;
    std::deque<std::size_t> primes;
    
    std::size_t p = pf.Next();
    while (p < LIMIT)
    {
        primes.push_back(p);
        p = pf.Next();
    }
    
    typedef std::pair<std::size_t, std::size_t> PrimeSum;
    
    PrimeSum max(0, 0);
    for (std::size_t i = 0; i != primes.size(); ++i)
    {
        PrimeSum ps(0, 0);
        std::size_t j = i;
        while (j != primes.size())
        {
            ps.first += primes[j];
            ++ps.second;
            
            if (ps.first > LIMIT)
                break;
            
            if (ps.second > max.second && pf.CheckPrime(ps.first))
                max = ps;
            
            ++j;
        }
    }
    
    std::cout << "Prime: " << max.first << ", no of terms: " << max.second << std::endl;
    
    return 0;
}
