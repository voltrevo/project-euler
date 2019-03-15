#include <cassert>
#include <iostream>
#include <map>

#include "primeTester.hpp"

int SummationCount(int sum, int upperLimit, const PrimeTester& pt)
{
    static std::map<std::pair<int, int>, int> cache;
    
    if (sum == 0)
        return 1;
    
    if (upperLimit == 0)
        return 0;
    
    if (upperLimit > sum)
        upperLimit = sum;
    
    assert(sum >= 0 && upperLimit >= 0);
    assert(!(sum == 0 && upperLimit == 0));
    
    std::map<std::pair<int, int>, int>::iterator location = cache.find(
        std::make_pair(sum, upperLimit));
    
    if (location != cache.end())
        return location->second;
    
    int result = (
        SummationCount(sum, upperLimit - 1, pt) +
        (pt(upperLimit) ? SummationCount(sum - upperLimit, upperLimit, pt) : 0));
    
    cache[std::make_pair(sum, upperLimit)] = result;
    
    return result;
}

int main()
{
    PrimeTester pt(100000);
    int sum = 0;
    int summations = 0;
    while (summations <= 5000)
    {
        ++sum;
        summations = SummationCount(sum, sum, pt);
        if (pt(sum))
            --summations;
        
        std::cout << sum << ": " << summations << std::endl;
    }
    
    return 0;
}
