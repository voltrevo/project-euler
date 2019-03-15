#include <iostream>

int main()
{
    double max = 0;
    int nMax = -1;
    
    for (int d = 8; d != 1000000; ++d)
    {
        if (d % 7 == 0)
            continue;
        
        int n = d * 3 / 7;
        double val = 1.0 * n / d;
        if (val > max)
        {
            max = val;
            nMax = n;
        }
    }
    
    std::cout << nMax << std::endl;
    
    return 0;
}
