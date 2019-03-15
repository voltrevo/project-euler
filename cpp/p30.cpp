#include <iostream>
using namespace std;

int Digit5thPowerSum(int x)
{
    int d, d2;
    int sum = 0;
    while (x != 0)
    {
        d = x % 10;
        x /= 10;
        
        d2 = d * d;
        sum += d2 * d2 * d;
    }
    
    return sum;
}

int main()
{
    int sum = 0;
    for (int i = 2; i != 354294; ++i)
        if (Digit5thPowerSum(i) == i)
            sum += i;
    
    cout << sum << endl;
    
    return 0;
}
