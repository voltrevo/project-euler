#include <cassert>
#include <cmath>
#include <iostream>

int SqRootCycleFinder(int n)
{
    int k = std::sqrt(n);
    
    if (k * k == n)
        return 0;
    
    int d = 1;
    int b = k;
    
    int i = 0;
    
    do
    {
        assert((n - b * b) % d == 0);
        d = (n - b * b) / d;
        b = k - (b + k) % d;
        ++i;
    }
    while (!((d == 1) && (b == k)));
    
    return i;
}

int main()
{
    int count = 0;
    
    for (int i = 0; i != 10000; ++i)
    {
        if (SqRootCycleFinder(i) % 2 == 1)
            ++count;
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
