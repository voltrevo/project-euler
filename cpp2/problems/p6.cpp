#include <ranges>
#include <iostream>

#include "util/fold_left.hpp"

int main() {
    int sumOfSq = std::views::iota(1, 101)
        | std::views::transform([](int x) { return x * x; })
        | fold_left(0, std::plus{});
    
    int sum = std::views::iota(1, 101)
        | fold_left(0, std::plus{});
    
    int sqOfSum = sum * sum;

    std::cout << sqOfSum - sumOfSq << std::endl;
}
