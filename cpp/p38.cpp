#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int CheckPandigital(int x)
{
    bool digitUsed[10];
    for (int i = 0; i != 10; ++i)
        digitUsed[i] = false;
    
    stringstream ss;
    
    int totalDigits = 0;
    int n = 1;
    while (!digitUsed[0] && totalDigits < 9)
    {
        int y = n * x;
        ss << y;
        while (y != 0)
        {
            if (digitUsed[y % 10])
                return false;
            
            digitUsed[y % 10] = true;
            y /= 10;
            ++totalDigits;
        }
        
        ++n;
    }
    
    return (!digitUsed[0] && totalDigits == 9 && n != 2 ? atoi(ss.str().c_str()) : 0);
}

int main()
{
    int largest = 0;
    for (int i = 1; i != 100000; ++i)
        if (CheckPandigital(i) > largest)
            largest = CheckPandigital(i);
    
    cout << largest << endl;
    
    return 0;
}
