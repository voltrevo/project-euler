#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "boost/cstdint.hpp"

/*
bool IsTriadSum(int l)
{
    if (l % 2 != 0)
        return false;
    
    int z = l / 2;
    double lower = std::sqrt(z / 2.0);
    double upper = std::sqrt(1.0 * z);
    
    for (int m = static_cast<int>(lower + 1); m < upper; ++m)
    {
        if (z % m == 0)
            return true;
    }
    
    return false;
}
*/

int GCD(int a, int b)
{
    while (std::min(a, b) != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    
    return std::max(a, b);
}

int main()
{
    std::vector<int> validLengths(1500000);
    for (int i = 0; i != 1500000; ++i)
        validLengths[i] = 0;
    
    for (int m = 2; m != 1732; ++m)
    {
        for (int n = 1; n != m; ++n)
        {
            if (GCD(m, n) == 1 && (m % 2 == 0 || n % 2 == 0))
            {
                int L = 2 * m * (m + n);
                
                for (int Ln = L; Ln < 1500000; Ln += L)
                    ++validLengths[Ln];
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i != 1500000; ++i)
    {
        if (validLengths[i] == 1)
            ++count;
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
