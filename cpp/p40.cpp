#include <iostream>
using namespace std;

int NthDigit(int n)
{
    int digitsOfOwner = 1;
    int sum = 0;
    int tenPow = 1;
    while (sum <= n)
    {
        sum += 9 * digitsOfOwner * tenPow;
        tenPow *= 10;
        ++digitsOfOwner;
    }
    
    tenPow /= 10;
    --digitsOfOwner;
    sum -= 9 * digitsOfOwner * tenPow;
    
    int remainingDigits = n - sum;
    int remainingNumbers = (remainingDigits + digitsOfOwner - 1) / digitsOfOwner;
    
    int owner = tenPow - 1 + remainingNumbers;
    
    int excessDigits = remainingNumbers * digitsOfOwner - remainingDigits;
    
    for (int i = 0; i != excessDigits; ++i)
        owner /= 10;
    
    return owner % 10;
}

int main()
{
    int product = 1;
    for (int tenPow = 1; tenPow != 10 * 1000 * 1000; tenPow *= 10)
        product *= NthDigit(tenPow);
    
    cout << product << endl;
    
    return 0;
}
