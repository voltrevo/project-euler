#include <cassert>
#include <iostream>
#include <map>

int SummationCount(int sum, int upperLimit)
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
    
    int result = SummationCount(sum, upperLimit - 1) + SummationCount(sum - upperLimit, upperLimit);
    
    cache[std::make_pair(sum, upperLimit)] = result;
    
    return result;
}

int main()
{
    std::cout << SummationCount(100, 100) - 1 << std::endl;
    
    return 0;
}
