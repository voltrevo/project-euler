#include <algorithm>
#include <iostream>
#include <string>

#include "boost/cstdint.hpp"
#include "boost/lexical_cast.hpp"

#include "gmpxx.h"

bool IsLychrel(mpz_class n)
{
    std::string norm;
    std::string rev;
    
    int i = 0;
    
    while (i < 55)
    {
        norm = boost::lexical_cast<std::string>(n);
        rev = norm;
        reverse(rev.begin(), rev.end());
        
        if (norm == rev && i != 0)
            return false;
        
        n = boost::lexical_cast<mpz_class>(norm) + boost::lexical_cast<mpz_class>(rev);
        
        ++i;
    }
    
    return true;
}

int main()
{
    mpz_class sum = 0;
    
    for (mpz_class i = 0; i != 10000; ++i)
        sum += (IsLychrel(i) ? 1 : 0);
    
    std::cout << sum << std::endl;
    
    return 0;
}
