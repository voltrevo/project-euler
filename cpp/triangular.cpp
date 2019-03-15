#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 0; i != 200; ++i)
    {
        sum += i;
        std::cout << i << ": " << sum << std::endl;
    }
    
    return 0;
}
