#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i != 6; ++i)
        cout << "Hello "[i] << ' ';
    
    for (int i = 0; i != 6; ++i)
        cout << *("World!" + i) << ' ';
    
    cout << endl;
    
    return 0;
}
