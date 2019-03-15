#include <iostream>
#include <utility>
using namespace std;

#include "primeFeed.hpp"

int DivLength(int divisor)
{
    int rem1 = 1;
    int rem2 = 1;
    
    do
    {
        // Haire and tortoise
        rem1 = (rem1 * 10) % divisor;
        rem2 = (rem2 * 10) % divisor;
        rem2 = (rem2 * 10) % divisor;
    }
    while (rem1 != rem2);
    
    int length = 0;
    do
    {
        rem2 = (rem2 * 10) % divisor;
        ++length;
    }
    while (rem1 != rem2);
    
    return length;
}

int main()
{
    pair<int, int> largestDivLen(0, 0);
    for (pair<int, int> divLen(1, 1); divLen.first != 1000; ++divLen.first)
    {
        divLen.second = DivLength(divLen.first);
        if (divLen.second > largestDivLen.second)
            largestDivLen = divLen;
    }
    
    cout << "(" << largestDivLen.first << ", " << largestDivLen.second << ")" << endl;
    
    return 0;
}
