#include <cassert>
#include <deque>
#include <iostream>

int main()
{
    std::deque<int> sumCounts;
    sumCounts.push_back(1); // p(0) = 1
    
    while (sumCounts.back() % 1000000 != 0)
    {
        sumCounts.push_back(0);
        int n = 1;
        int mn = -1;
        int multiplier = 1;
        while (true)
        {
            int pent = n * (3 * n - 1) / 2;
            int index = sumCounts.size() - pent - 1;
            if (index < 0)
                break;
            
            if (multiplier == 1)
                sumCounts.back() += sumCounts[index];
            else
                sumCounts.back() -= sumCounts[index];
            
            pent = mn * (3 * mn - 1) / 2;
            index = sumCounts.size() - pent - 1;
            if (index < 0)
                break;
            
            if (multiplier == 1)
                sumCounts.back() += sumCounts[index];
            else
                sumCounts.back() -= sumCounts[index];
            
            sumCounts.back() += 3 * 1000 * 1000;
            sumCounts.back() %= 1000 * 1000;
            
            ++n;
            --mn;
            multiplier *= -1;
        }
    }
    
    std::cout << sumCounts.size() - 1 << std::endl;
    std::cout << sumCounts.back() << std::endl;
    
    return 0;
}
