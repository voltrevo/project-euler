#include <algorithm>
#include <iostream>
#include <list>

bool CheckPrime(std::size_t n)
{
    for (std::size_t i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    
    return true;
}

int main()
{
    int digits = 1;
    int digitLimit = 11;
    int base11Num = 0;
    int base10Qualifier = 1;
    
    while (digits < 8)
    {
        int hits = 0;
        int first = -1;
        
        for (int insertDigit = 0; insertDigit != 10; ++insertDigit)
        {
            int resultNum = 0;
            int numCopy = base11Num;
            bool containsStar = false;
            
            while (numCopy > 0)
            {
                resultNum *= 10;
                
                if (numCopy % 11 == 10)
                {
                    resultNum += insertDigit;
                    containsStar = true;
                }
                else
                {
                    resultNum += numCopy % 11;
                }
                
                numCopy /= 11;
            }
            
            if (!containsStar)
                continue;
            
            if (resultNum < base10Qualifier)
                continue;
            
            if (CheckPrime(resultNum))
            {
                if (hits == 0)
                    first = resultNum;
                
                ++hits;
            }
        }
        
        if (hits > 6)
        {
            std::cout << hits << ", " << first << std::endl;
        }
        
        ++base11Num;
        if (base11Num == digitLimit)
        {
            ++digits;
            base10Qualifier *= 10;
            digitLimit *= 11;
        }
    }
}
