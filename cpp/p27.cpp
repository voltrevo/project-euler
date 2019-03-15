#include <iostream>
#include <utility>
using namespace std;

#include "primeFeed.hpp"

PrimeFeed pf;

bool SignedCheckPrime(int x)
{
    return x > 1 && pf.CheckPrime(x);
}

int QuadPrimeLength(int a, int b)
{
    int n = 0;
    while (SignedCheckPrime(n * n + a * n + b))
        ++n;
    
    return n;
}

struct QuadPrimeData
{
    int a;
    int b;
    int pLen;
};

int main()
{
    QuadPrimeData longest;
    longest.pLen = -1;
    
    QuadPrimeData qpd;
    for (qpd.a = -999; qpd.a != 999; qpd.a += 2)
    {
        for (qpd.b = pf.Next(); qpd.b < 1000; qpd.b = pf.Next())
        {
            qpd.pLen = QuadPrimeLength(qpd.a, qpd.b);
            if (qpd.pLen > longest.pLen)
                longest = qpd;
        }
        
        pf.Restart();
    }
    
    cout << "n^2 + " << longest.a << "n + " << longest.b
         << ": " << longest.pLen << endl;
    
    return 0;
}
