#include <cmath>
#include <iostream>
#include <utility>
using namespace std;

int main()
{
    pair<int, int> most(0, 0);
    for (int p = 3; p != 1001; ++p)
    {
        pair<int, int> curr(p, 0);
        for (int a = 1; a != p / 3; ++a)
        {
            int c = ((p - a) * (p - a) + a * a) / (2 * (p - a));
            int b = p - a - c;
            if (a * a + b * b == c * c)
                ++curr.second;
        }
        
        if (curr.second > most.second)
            most = curr;
    }
    
    cout << "Sum: " << most.first << ", count: " << most.second << endl;
    
    return 0;
}
