#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int main()
{
    PrimeFeed pf;
    
    char digits[] = "123456789";
    int largest = 0;
    int x;
    
    int i = 7;
    while (i > 0 && largest == 0)
    {
        assert(strcmp(digits, "123456789") == 0);
        swap(digits[i], digits[9]); // Swap null into index i to make length i
        
        // Start with largest permutation
        next_permutation(digits, digits + i, greater<char>());
        
        do
        {
            x = atoi(digits);
            if (pf.CheckPrime(x))
                largest = x;
        }
        while (next_permutation(digits, digits + i, greater<char>()) && largest == 0);
        
        next_permutation(digits, digits + i, less<char>());
        
        swap(digits[i], digits[9]);
        i -= 3;
    }
    
    cout << largest << endl;
    
    return 0;
}
