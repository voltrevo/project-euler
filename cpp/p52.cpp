#include <iostream>
#include <set>

void FillDigitSet(std::size_t n, std::multiset<std::size_t>& digitSet)
{
    while (n > 0)
    {
        digitSet.insert(n % 10);
        n /= 10;
    }
}

int main()
{
    for (int i = 0; i != 1000000; ++i)
    {
        std::multiset<std::size_t> set1;
        FillDigitSet(i, set1);
        
        bool plausible = true;
        for (int mul = 2; mul != 7 && plausible; ++mul)
        {
            std::multiset<std::size_t> setn;
            FillDigitSet(i * mul, setn);
            plausible &= (set1 == setn);
        }
        
        if (plausible)
            std::cout << i << std::endl;
    }
    
    return 0;
}
