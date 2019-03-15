#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

#include "gmpxx.h"

template <typename T>
void Swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

mpz_class PathCount(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    
    if (i > j)
        Swap(i, j);
    
    static map<pair<int, int>, mpz_class> cache;
    if (cache.find(make_pair(i, j)) != cache.end())
        return cache[make_pair(i, j)];
    
    mpz_class sum = 0;
    
    if (i != 0)
        sum += PathCount(i - 1, j);
    
    if (j != 0)
        sum += PathCount(i, j - 1);
    
    cache[make_pair(i, j)] = sum;
    
    return sum;
}

int main(int argc, char** argv)
{
    if (argc != 3)
        return 1;
    
    cout << PathCount(atoi(argv[1]), atoi(argv[2])) << endl;
    
    return 0;
}
