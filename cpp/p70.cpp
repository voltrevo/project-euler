#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>

#include "boost/lexical_cast.hpp"

#include "primeTester.hpp"

PrimeTester pt(10000000);
std::list<int> primes;

/*
int Totient(int n)
{
    std::list<int> primeFactors;
    int nCopy = n;
    int p = 2;
    while (nCopy > 1)
    {
        assert(p <= n);
        if (nCopy % p == 0)
        {
            primeFactors.push_back(p);
            nCopy /= p;
            while (nCopy % p == 0)
                nCopy /= p;
        }
        
        ++p;
        while (!pt(p))
            ++p;
    }
    
    int result = 0;
    
    for (int i = 1; i <= n; ++i)
    {
        ++result;
        for (std::list<int>::iterator it = primeFactors.begin(); it != primeFactors.end(); ++it)
        {
            if (i % *it == 0)
            {
                --result;
                break;
            }
        }
    }
    
    return result;
}
*/

int Totient(int n, std::list<int>::iterator firstPermissiblePrime, double lowerBound)
{
    int nCopy = n;
    int result = n;
    std::list<int>::iterator p = firstPermissiblePrime;
    while (nCopy > 1)
    {
        assert(p != primes.end());
        assert(*p <= n);
        if (nCopy % *p == 0)
        {
            result = result / *p * (*p - 1);
            if (result < lowerBound)
                return 1;
            nCopy /= *p;
            while (nCopy % *p == 0)
                nCopy /= *p;
        }
        
        ++p;
    }
    
    return result;
}

bool SameDigits(int a, int b)
{
    if (a > 10 * b || b > 10 * a)
        return false;
    
    std::string aStr = boost::lexical_cast<std::string>(a);
    std::string bStr = boost::lexical_cast<std::string>(b);
    std::sort(aStr.begin(), aStr.end());
    std::sort(bStr.begin(), bStr.end());
    return (aStr == bStr);
}

int main()
{
    for (int i = 1; i != 10000000; ++i)
    {
        if (pt(i))
            primes.push_back(i);
    }
    
    double min = 100;
    int numMin = -1;
    
    std::list<int>::iterator firstPermissiblePrime = primes.begin();
    std::list<int>::iterator nextPrime = firstPermissiblePrime;
    ++nextPrime;
    
    for (int i = 2; i != 10000000; ++i)
    {
        if (i % 10000 == 0)
        {
            std::cout << i << std::endl;
        }
        
        bool okToTest = true;
        for (std::list<int>::iterator p = primes.begin(); p != firstPermissiblePrime; ++p)
        {
            if (i % *p == 0)
            {
                okToTest = false;
                break;
            }
        }
        
        if (!okToTest)
            continue;
        
        int totient = Totient(i, firstPermissiblePrime, i / min);
        if (SameDigits(i, totient))
        {
            std::cout << i << ", " << totient << std::endl;
            double ratio = static_cast<double>(i) / totient;
            if (ratio < min)
            {
                min = ratio;
                numMin = i;
                
                while ((*nextPrime - 1.0) / *nextPrime < 1 / min)
                {
                    ++firstPermissiblePrime;
                    ++nextPrime;
                    assert(nextPrime != primes.end());
                    std::cout << "Now first permissible prime is: " << *firstPermissiblePrime;
                    std::cout << std::endl;
                }
            }
        }
    }
    
    std::cout << numMin << std::endl;
    
    return 0;
}
