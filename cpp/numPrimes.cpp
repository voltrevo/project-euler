#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "primeFeed.hpp"

int main(int argc, char** argv)
{
    assert(argc == 2);
    int num = atoi(argv[1]);
    PrimeFeed pf;
    for (int i = 0; i != num; ++i)
        pf.Next();
    
    return 0;
}
