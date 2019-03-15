#include <iostream>
using namespace std;

void PrintByte(unsigned char x)
{
    for (int i = 0; i != 8; ++i)
        cout << (((x >> (7 - i)) & 1) == 0 ? 0 : 1);
    
    cout << endl;
    
    for (int i = 0; i != 8; ++i)
        cout << (((x >> (7 - i)) % 2) == 0 ? 0 : 1);
    
    cout << endl;
}

int main()
{
    unsigned char x = 0x10;
    PrintByte(x);
    
    //unsigned char y = x >> 7;
    //cout << (y & 1) << endl;
    //cout << (y % 2) << endl;
    
    return 0;
}
