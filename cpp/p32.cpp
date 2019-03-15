#include <iostream>
#include <set>
using namespace std;

bool CheckPandigital(int a, int b, int c)
{
    bool digitUsed[10];
    for (int i = 0; i != 10; ++i)
        digitUsed[i] = false;
    
    int n[3] = {a, b, c};
    
    int totalDigits = 0;
    for (int i = 0; i != 3; ++i)
    {
        while (n[i] != 0)
        {
            if (digitUsed[n[i] % 10])
                return false;
            
            digitUsed[n[i] % 10] = true;
            n[i] /= 10;
            ++totalDigits;
        }
    }
    
    return !digitUsed[0] && totalDigits == 9;
}

int main()
{
    set<int> products;
    
    for (int a = 1; a != 10000; ++a)
        for (int b = 1; a * b < 10000; ++b)
            if (CheckPandigital(a, b, a * b))
                products.insert(a * b);
    
    int sum = 0;
    for (set<int>::iterator i = products.begin(); i != products.end(); ++i)
        sum += *i;
    
    cout << sum << endl;
    
    return 0;
}
