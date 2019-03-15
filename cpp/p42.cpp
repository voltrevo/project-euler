#include <deque>
#include <fstream>
#include <iostream>
using namespace std;

bool CheckTriangular(int x)
{
    static deque<bool> triFlags;
    static int nextDiff = 2;
    static int untilNext = 1;
    
    while (x >= triFlags.size())
    {
        if (untilNext == 0)
        {
            triFlags.push_back(true);
            untilNext = nextDiff;
            ++nextDiff;
        }
        else
        {
            triFlags.push_back(false);
        }
        
        --untilNext;
    }
    
    return triFlags[x];
}

int WordScore(const string& word)
{
    int sum = 0;
    for (int i = 0; i != word.size(); ++i)
        sum += word[i] - 'A' + 1;
    
    return sum;
}

int main()
{
    ifstream ifs("words.txt");
    string word;
    int count = 0;
    
    ifs >> word;
    while (!ifs.eof())
    {
        if (CheckTriangular(WordScore(word)))
            ++count;
        
        ifs >> word;
    }
    
    cout << count << endl;
    
    return 0;
}
