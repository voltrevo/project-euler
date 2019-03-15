#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int fib[3] = {1, 1, 2};
    int index = 2;
    while (fib[index] < 4 * 1000 * 1000)
    {
        if (fib[index] % 2 == 0)
            sum += fib[index];
        
        index = (index + 1) % 3;
        
        fib[index] = fib[(index + 1) % 3] + fib[(index + 2) % 3];
    }
    
    cout << sum << endl;
    
    return 0;
}
