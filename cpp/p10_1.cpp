#include <cstdlib>
#include <iostream>
using namespace std;

int PrimeSum(int limit)
{
    bool* flags = new bool[limit];
    for (int i = 0; i < limit; ++i)
        flags[i] = true;
    
    int prime = 2;
    int sum = 0;
    
    while (prime * prime < limit)
    {
        while (!flags[prime])
            ++prime;
        
        for (int multiple = prime * 2; multiple < limit; multiple += prime)
            flags[multiple] = false;
        
        sum += prime;
        ++prime;
    }
    
    while (prime < limit)
    {
        while (prime < limit && !flags[prime])
            ++prime;
        
        if (prime < limit)
            sum += prime;
        
        ++prime;
    }
    
    return sum;
}

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;
    
    cout << PrimeSum(atoi(argv[1])) << endl;
    
    return 0;
}
