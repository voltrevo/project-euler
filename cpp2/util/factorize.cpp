#include "util/gen_primes.hpp"

generator<int> factorize(uint64_t n) {
    for (int p: gen_primes()) {
        while (n % p == 0) {
            n /= p;
            co_yield p;
        }

        if (p * p > n) {
            if (n > 1) {
                co_yield n;
            }

            break;
        }
    }
}
