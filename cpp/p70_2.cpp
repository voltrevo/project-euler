#include <algorithm>
#include <iostream>
#include <list>

#include "boost/lexical_cast.hpp"

#include "primeTester.hpp"

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
    std::list<int> primes;
    PrimeTester pt(10000000);
    
    for (int i = 500; i != 4000; ++i)
    {
        if (pt(i))
            primes.push_back(i);
    }
    
    double min = 100;
    int nMin = -1;
    
    for (std::list<int>::iterator p = primes.begin(); p != primes.end(); ++p)
    {
        std::list<int>::iterator p2 = p;
        ++p2;
        for (; p2 != primes.end() && *p * *p2 < 10000000; ++p2)
        {
            int num = *p * *p2;
            int totient = (*p - 1) * (*p2 - 1);
            if (SameDigits(num, totient))
            {
                std::cout << num << ", " << totient << std::endl;
                if (1.0 * num / totient < min)
                {
                    min = 1.0 * num / totient;
                    nMin = num;
                }
            }
        }
    }
    
    std::cout << nMin << std::endl;
    
    return 0;
}
