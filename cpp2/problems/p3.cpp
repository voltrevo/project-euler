#include <iostream>

#include "util/factorize.hpp"
#include "util/generator.hpp"
#include "util/fold_left.hpp"

generator<int> factorize(uint64_t n);

template <typename T>
T max(T x, T y);

int main() {
    int largest_factor = factorize(600851475143ull)
        | fold_left(0, max<int>);

    std::cout << largest_factor << std::endl;

    return 0;
}

template <typename T>
T max(T x, T y) {
    return x > y ? x : y;
}
