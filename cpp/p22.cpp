#include <cassert>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
using namespace std;

int CharSum(const string& s)
{
    int sum = 0;
    for (int i = 0; i != s.size(); ++i)
    {
        sum += s[i] - 'A' + 1;
    }
    
    return sum;
}

int main()
{
    ifstream ifs("names.txt");
    list<string> nameList;
    
    string s;
    
    ifs >> s;
    while (!ifs.eof())
    {
        nameList.push_back(s);
        ifs >> s;
    }
    
    ifs.close();
    
    nameList.sort();
    
    int sum = 0;
    int sz = nameList.size();
    list<string>::iterator it = nameList.begin();
    for (int i = 0; i != sz; ++i)
    {
        sum += (i + 1) * CharSum(*it);
        ++it;
    }
    
    cout << sum << endl;
    
    return 0;
}
