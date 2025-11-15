#include <ranges>
#include <iostream>

#include "util/gen_primes.hpp"

int main() {
    int p10001 = *(gen_primes() | std::views::drop(10000)).begin();

    std::cout << p10001 << std::endl;
}
