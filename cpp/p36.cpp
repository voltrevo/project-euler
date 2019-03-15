#include <iostream>
using namespace std;

bool PalindromeInBase(int x, int base)
{
    int digits[32];
    bool couldBePalindrome = true;
    
    int pos = 0;
    while (x != 0)
    {
        digits[pos++] = x % base;
        x /= base;
    }
    
    int left = 0;
    int right = pos - 1;
    while (left < right && couldBePalindrome)
        couldBePalindrome = digits[left++] == digits[right--];
    
    return couldBePalindrome;
}

int main()
{
    int sum = 0;
    for (int i = 1; i != 1000000; ++i)
        if (PalindromeInBase(i, 10) && PalindromeInBase(i, 2))
            sum += i;
    
    cout << sum << endl;
    
    return 0;
}
