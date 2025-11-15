#include <iostream>
#include <ranges>

#include "util/fold_left.hpp"
#include "util/generator.hpp"

generator<int> fibonacci() {
    int a = 1;
    int b = 2;

    co_yield a;
    co_yield b;

    while (true) {
        int c = a + b;
        a = b;
        b = c;

        co_yield b;
    }
}

int main() {
    using namespace std::views;

    auto sum = fibonacci()
        | take_while([](int x) { return x < 4000000; })
        | filter([](int x) { return x % 2 == 0; })
        | fold_left(0, std::plus{});

    std::cout << sum << std::endl;

    return 0;
}
