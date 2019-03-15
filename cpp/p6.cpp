#include <iostream>
using namespace std;

int main()
{
    int sumSquare = 0;
    int squaresSum = 0;
    for (int i = 1; i != 101; ++i)
    {
        sumSquare += i;
        squaresSum += i * i;
    }
    
    sumSquare *= sumSquare;
    
    cout << sumSquare - squaresSum << endl;
    
    return 0;
}
