#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>

#include "gmpxx.h"

#include "boost/cstdint.hpp"

boost::int64_t MinDiophantineOld(boost::int64_t d)
{
    boost::int64_t x;
    boost::int64_t y = 1;
    
    while (true)
    {
        x = std::sqrt(1 + d * y * y);
        
        if (x * x - d * y * y == 1)
            break;
        
        ++y;
    }
    
    return x;
}

std::deque<int> SqRootContFraction(int n)
{
    int k = std::sqrt(n);
    
    if (k * k == n)
        assert(false);
    
    int d = 1;
    int b = k;
    
    std::deque<int> a;
    a.push_back(k);
    
    int i = 0;
    
    do
    {
        assert((n - b * b) % d == 0);
        d = (n - b * b) / d;
        a.push_back((k + b) / d);
        b = k - (b + k) % d;
        ++i;
    }
    while (!((d == 1) && (b == k)));
    
    return a;
}

mpq_class ContFractionToConvergent(const std::deque<int>& frac, int depth)
{
    mpq_class result = 0;
    
    while (depth > 1)
    {
        result += frac[1 + (depth - 2) % (frac.size() - 1)];
        result = 1 / result;
        --depth;
    }
    
    result += frac[0];
    
    return result;
}

mpz_class MinDiophantine(int d)
{
    std::deque<int> frac = SqRootContFraction(d);
    mpq_class q = ContFractionToConvergent(frac, 1);
    
    int i = 1;
    
    while (q.get_num() * q.get_num() - d * q.get_den() * q.get_den() != 1)
    {
        ++i;
        q = ContFractionToConvergent(frac, i);
    }
    
    return q.get_num();
}

int main()
{
    mpz_class max = 0;
    int maxD = 0;
    int drt;
    mpz_class dioph;
    
    for (int d = 2; d != 1001; ++d)
    {
        drt = std::sqrt(d);
        
        if (drt * drt == d)
            continue;
        
        dioph = MinDiophantine(d);
        
        if (dioph > max)
        {
            max = dioph;
            maxD = d;
            //std::cout << maxD << ", " << max << std::endl;
        }
    }
    
    std::cout << maxD << std::endl;
    std::cout << max << std::endl;
    
    return 0;
}
