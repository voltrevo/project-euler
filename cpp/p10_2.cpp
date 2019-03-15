#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;
    
    int limit = atoi(argv[1]);
    
    list<int> primes;
    int x = 3;
    bool couldBePrime;
    list<int>::iterator i;
    
    primes.push_back(2);
    
    while (primes.back() < limit)
    {
        couldBePrime = true;
        i = primes.begin();
        while (couldBePrime && i != primes.end() && *i * *i <= x)
        {
            couldBePrime = x % *i != 0;
            ++i;
        }
        
        if (couldBePrime)
            primes.push_back(x);
        
        ++x;
    }
    
    primes.pop_back();
    
    int sum = 0;
    for (i = primes.begin(); i != primes.end(); ++i)
        sum += *i;
    
    cout << sum << endl;
    
    return 0;
}
