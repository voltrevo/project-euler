#include <deque>
#include <iostream>
using namespace std;

bool IsPalindrome(int x)
{
    deque<int> digits;
    while (x != 0)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    
    int left = 0;
    int right = digits.size() - 1;
    while (left < right)
    {
        if (digits[left] != digits[right])
            return false;
        
        ++left;
        --right;
    }
    
    return true;
}

int main()
{
    int largest = -1;
    for (int i = 100; i != 1000; ++i)
        for (int j = 100; j != 1000; ++j)
            if (IsPalindrome(i * j) && i * j > largest)
                largest = i * j;
    
    cout << largest << endl;
    
    return 0;
}
