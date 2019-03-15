#include <iostream>

bool CheckPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int main()
{
    int sideLength = 3;
    int primeCount = 0;
    while (true)
    {
        if (CheckPrime(sideLength * sideLength - sideLength + 1))
            ++primeCount;
        
        if (CheckPrime(sideLength * sideLength - 2 * sideLength + 2))
            ++primeCount;
        
        if (CheckPrime(sideLength * sideLength - 3 * sideLength + 3))
            ++primeCount;
        
        if (primeCount * 10 < 2 * sideLength - 1)
            break;
        
        sideLength += 2;
    }
    
    std::cout << sideLength << std::endl;
    
    return 0;
}
