#include "util/generator.hpp"

generator<int> gen_primes_from_5();
bool is_prime_ignore_2_3(int n);

generator<int> gen_primes() {
    co_yield 2;
    co_yield 3;
    
    int x = 5;

    while (true) {
        if (is_prime_ignore_2_3(x)) {
            co_yield x;
        }

        x += 2;

        if (is_prime_ignore_2_3(x)) {
            co_yield x;
        }

        x += 4;
    }
}

generator<int> gen_primes_from_5() {
    int x = 5;

    while (true) {
        if (is_prime_ignore_2_3(x)) {
            co_yield x;
        }

        x += 2;

        if (is_prime_ignore_2_3(x)) {
            co_yield x;
        }

        x += 4;
    }
}

bool is_prime_ignore_2_3(int n) {
    if (n < 25) {
        return true;
    }

    for (int p: gen_primes_from_5()) {
        if (p * p > n) {
            break;
        }

        if (n % p == 0) {
            return false;
        }
    }

    return true;
}
