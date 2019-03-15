#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
    deque<int> P;
    
    for (int i = 1; i != 20001; ++i)
        P.push_back(i * (3 * i - 1) / 2);
    
    int lowest = 1000000000;
    for (int i = 1; i != 10001; ++i)
    {
        for (int j = i + 1; j != 10001; ++j)
        {
            if
            (
                P[j] - P[i] < lowest &&
                binary_search(P.begin(), P.end(), P[i] + P[j]) &&
                binary_search(P.begin(), P.end(), P[j] - P[i])
            )
            {
                lowest = P[j] - P[i];
            }
        }
    }
    
    cout << lowest << endl;
    
    return 0;
}
