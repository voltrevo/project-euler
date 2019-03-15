#include <cassert>
#include <iostream>
using namespace std;

int Factorial(int x)
{
    if (x == 0)
        return 1;
    
    assert(x > 0);
    int product = x;
    while (x != 1)
        product *= --x;
    
    return product;
}

int FactorialDigitSum(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += Factorial(x % 10);
        x /= 10;
    }
    
    return sum;
}

int main()
{
    int sum = 0;
    for (int i = 3; i != 2540160; ++i)
        if (FactorialDigitSum(i) == i)
            sum += i;
    
    cout << sum << endl;
    
    return 0;
}
