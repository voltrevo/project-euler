#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs("primes1.txt");
    
    int p;
    int sum = 0;
    
    ifs >> p;
    while (!ifs.eof())
    {
        sum += p;
        ifs >> p;
    }
    
    ifs.close();
    
    cout << sum << endl;
    
    return 0;
}
