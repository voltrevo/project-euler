#include <cassert>
#include <iostream>
#include <list>
#include <string>
using namespace std;

string Permute(const string& s, int permuteNum)
{
    string result(s);
    
    while (permuteNum != 0)
    {
        int factorial = 1;
        int factN = 1;
        
        while (factorial <= permuteNum)
        {
            ++factN;
            factorial *= factN;
        }
        
        factorial /= factN;
        --factN;
        
        int digit = permuteNum / factorial;
        permuteNum = permuteNum % factorial;
        
        int firstPos = result.size() - 1 - factN;
        assert(firstPos >= 0);
        
        int pos = firstPos + digit;
        char tmp = result[pos];
        for (; pos != firstPos; --pos)
            result[pos] = result[pos - 1];
        
        result[pos] = tmp;
    }
    
    return result;
}

int main()
{
    cout << Permute("0123456789", 999999) << endl;
    
    return 0;
}
