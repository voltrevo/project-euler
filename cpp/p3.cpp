#include <cstdlib>
#include <deque>
#include <iostream>
using namespace std;

#include <gmpxx.h>

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;
    
    mpz_class x(argv[1]);
    deque<int> primes;
    
    int primeCandidate = 2;
    while (x != 1)
    {
        bool couldBePrime;
        
        do
        {
            deque<int>::iterator i = primes.begin();
            couldBePrime = true;
            while (couldBePrime && i != primes.end() && *i * *i <= primeCandidate)
            {
                if (primeCandidate % *i == 0)
                {
                    couldBePrime = false;
                    ++primeCandidate;
                }
                
                ++i;
            }
        }
        while (!couldBePrime);
        
        primes.push_back(primeCandidate);
        
        int count = 0;
        while (x % primeCandidate == 0)
        {
            x /= primeCandidate;
            ++count;
        }
        
        if (count != 0)
            cout << primeCandidate << " ^ " << count << endl;
        
        ++primeCandidate;
    }
    
    return 0;
}
