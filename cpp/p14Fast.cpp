#include <cassert>
#include <iostream>
#include <utility>
using namespace std;

#include "boost/cstdint.hpp"

int CollatzLength(boost::uint64_t x)
{
    int i = 1;
    while (x != 1)
    {
        if (x % 2 == 0)
            x /= 2;
        else
            x = 3 * x + 1;
        
        ++i;
    }
    
    return i;
}

int main()
{
    pair<int, int> longestCollatz(0, 0);
    int length;
    
    for (int i = 1; i < 1000000; ++i)
    {
        length = CollatzLength(i);
        if (length > longestCollatz.second)
        {
            longestCollatz = make_pair(i, length);
            //cout << longestCollatz.first << ", " << longestCollatz.second << endl;
        }
    }
    
    cout << "Input:  " << longestCollatz.first << endl;
    cout << "Length: " << longestCollatz.second << endl;
    
    return 0;
}
