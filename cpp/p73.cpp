#include <cassert>
#include <algorithm>
#include <iostream>

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

int main(int argc, char** argv)
{
    assert(argc == 2);
    int count = 0;
    int limit = atoi(argv[1]) + 1;
    
    for (int d = 2; d != limit; ++d)
    {
        for (int n = d / 3 + 1; 1.0 * n / d < 0.5; ++n)
        {
            assert(1.0 * n / d > 1.0 / 3);
            if (GCD(n, d) == 1)
                ++count;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
