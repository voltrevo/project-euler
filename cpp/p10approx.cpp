#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    double sum = 0;
    for (int i = 2; i != 2000000; ++i)
        sum += i / log(i);
    
    cout << static_cast<int>(sum + 0.5) << endl;
    
    return 0;
}
