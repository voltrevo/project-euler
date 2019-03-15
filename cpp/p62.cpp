#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

#include "boost/cstdint.hpp"

int main()
{
    std::deque<std::pair<std::vector<int>, int> > cubes;
    
    for (boost::uint64_t i = 0; i != 300000; ++i)
    {
        cubes.push_back(std::pair<std::vector<int>, int>());
        cubes.back().second = i;
        boost::uint64_t digits = i * i * i;
        while (digits > 0)
        {
            cubes.back().first.push_back(digits % 10);
            digits /= 10;
        }
        std::sort(cubes.back().first.begin(), cubes.back().first.end());
    }
    
    std::sort(cubes.begin(), cubes.end());
    
    int repeats = 0;
    std::pair<std::vector<int>, int> firstOfRun;
    std::deque<std::pair<int, int> > results;
    for (auto it = cubes.begin(); it != cubes.end(); ++it)
    {
        if (it->first == firstOfRun.first)
        {
            ++repeats;
        }
        else
        {
            if (repeats > 1)
                results.push_back(std::make_pair(repeats, firstOfRun.second));
            
            repeats = 0;
            firstOfRun = *it;
        }
    }
    
    if (repeats > 1)
        results.push_back(std::make_pair(repeats, firstOfRun.second));
    
    std::sort(results.begin(), results.end());
    for (
        std::deque<std::pair<int, int> >::reverse_iterator rit = results.rbegin();
        rit != results.rend();
        ++rit)
    {
        std::cout << rit->second << ", repeats: " << rit->first << std::endl;
    }
    
    for (auto it = cubes.begin(); it != cubes.end(); ++it)
    {
        for (int x : it->first)
            std::cout << x << ' ';
        
        std::cout << ", " << it->second << std::endl;
    }
    
    return 0;
}
