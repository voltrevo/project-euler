#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> primes;
    int x = 2;
    bool couldBePrime;
    list<int>::iterator i;
    
    while (primes.size() != 10001)
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
    
    cout << primes.back() << endl;
    
    return 0;
}
