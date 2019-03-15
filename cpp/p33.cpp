#include <iostream>
#include <list>
using namespace std;

#include "primeFeed.hpp"

int HCF(int a, int b)
{
    static PrimeFeed pf;
    pf.Restart();
    
    if (a == 0 || b == 0)
        return 0;
    
    int product = 1;
    while (a != 1 || b != 1)
    {
        int p = pf.Next();
        
        while (a % p == 0 && b % p == 0)
        {
            product *= p;
            a /= p;
            b /= p;
        }
        
        while (a % p == 0)
            a /= p;
        
        while (b % p == 0)
            b /= p;
    }
    
    return product;
}

bool FractionsNonZeroAndEqual(int a, int b, int p, int q)
{
    if (a == 0 || b == 0 || p == 0 || q == 0)
        return false;
    
    int hcf = HCF(a, b);
    a /= hcf;
    b /= hcf;
    
    hcf = HCF(p, q);
    p /= hcf;
    q /= hcf;
    
    return a == p && b == q;
}

int main()
{
    int nProd = 1;
    int dProd = 1;
    
    for (int n = 10; n != 100; ++n)
    {
        for (int d = n + 1; d != 100; ++d)
        {
            if (n % 10 == 0 && d % 10 == 0)
                continue;
            
            if
            (
                (n % 10 == d % 10 && FractionsNonZeroAndEqual(n, d, n / 10, d / 10)) ||
                (n % 10 == d / 10 && FractionsNonZeroAndEqual(n, d, n / 10, d % 10)) ||
                (n / 10 == d % 10 && FractionsNonZeroAndEqual(n, d, n % 10, d / 10)) ||
                (n / 10 == d / 10 && FractionsNonZeroAndEqual(n, d, n % 10, d % 10))
            )
            {
                nProd *= n;
                dProd *= d;
            }
        }
    }
    
    cout << dProd / HCF(nProd, dProd) << endl;
    
    return 0;
}
