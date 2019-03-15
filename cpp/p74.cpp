#include <cassert>
#include <iostream>

int factorials[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int NonRepeatLength(int n)
{
    int count = 0;
    while (count != 61)
    {
        ++count;
        int nCopy = n;
        n = 0;
        while (nCopy > 0)
        {
            n += factorials[nCopy % 10];
            nCopy /= 10;
        }
        
        if (n == 0 || n == 1 || n == 2 || n == 145)
            return count + 1;
        else if (n == 169 || n == 1454 || n == 363601)
            return count + 3;
        else if (n == 871 || n == 872 || n == 45361 || n == 45362)
            return count + 2;
    }
    
    return -1;
}

int main()
{
    int count = 0;
    
    assert(NonRepeatLength(69) == 5);
    assert(NonRepeatLength(78) == 4);
    
    for (int i = 3; i != 1000000; ++i)
    {
        if (NonRepeatLength(i) == 60)
            ++count;
    }
    
    std::cout << count << std::endl;
    
    return 0;
}
