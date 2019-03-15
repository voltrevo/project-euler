#include <algorithm>
#include <iostream>

int main()
{
    char testStr[] = "nnn**";
    
    do
    {
        std::cout << testStr << std::endl;
    }
    while (std::prev_permutation(testStr, testStr + 5));
    
    return 0;
}
