#ifndef PRIME_TESTER_HPP
#define PRIME_TESTER_HPP

#include <cstddef>
#include <vector>

class PrimeTester
{
private:
    std::size_t mLimit;
    std::vector<bool> mPrimeCache;

public:
    PrimeTester(std::size_t limit);
    bool operator()(std::size_t n) const;
};

#endif
