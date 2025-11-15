#include <ranges>
#include <numeric>
#include <iostream>

#include "util/fold_left.hpp"

int main() {
    using namespace std::views;

    auto sum = iota(1, 1000)
        | filter([](int x) { return x % 3 == 0 || x % 5 == 0; })
        | fold_left(0, std::plus{});

    std::cout << sum << std::endl;

    return 0;
}
