#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::size_t> pascal, pascalBuf;
    pascal.resize(101, 0);
    pascalBuf.resize(101, 0);
    int milCount = 0;
    
    pascal[0] = 1;
    
    for (int row = 1; row != 101; ++row)
    {
        std::swap(pascal, pascalBuf);
        
        pascal[0] = 1;
        for (int col = 1; col != row + 1; ++col)
        {
            pascal[col] = std::min(pascalBuf[col] + pascalBuf[col - 1], 1000000lu);
            if (pascal[col] == 1000000)
                ++milCount;
        }
    }
    
    std::cout << milCount << std::endl;
    
    return 0;
}
