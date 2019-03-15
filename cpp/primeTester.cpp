#include "gmpxx.h"

#include "primeTester.hpp"

PrimeTester::PrimeTester(std::size_t limit)
:
    mLimit(limit)
{
    mPrimeCache.reserve(mLimit);
    
    for (std::size_t i = 0; i != mLimit; ++i)
        mPrimeCache.push_back(true);
    
    mPrimeCache[0] = false;
    mPrimeCache[1] = false;
    
    std::size_t p = 2;
    while (p * p <= mLimit)
    {
        for (std::size_t np = 2 * p; np < mLimit; np += p)
            mPrimeCache[np] = false;
        
        ++p;
        while (!mPrimeCache[p] && p * p <= mLimit)
            ++p;
    }
}

bool PrimeTester::operator()(std::size_t n) const
{
    if (n < mLimit)
        return mPrimeCache[n];
    
    mpz_class mpn = n;
    return (mpz_probab_prime_p(mpn.get_mpz_t(), 10) != 0);
}
