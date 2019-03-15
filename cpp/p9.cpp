#include <iostream>
using namespace std;

int main()
{
    int a;
    for (a = 1; a != 332; ++a)
        if ((1000 * (500 - a)) % (1000 - a) == 0)
            break;
    
    int b = 1000 * (500 - a) / (1000 - a);
    int c = 1000 - a - b;
    cout << a * b * c << endl;
    
    return 0;
}
