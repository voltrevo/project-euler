#include <ranges>
#include <numeric>
#include <iostream>

using namespace std::views;

int main() {
    auto rng = iota(1, 1000)
        | filter([](int x) { return x % 3 == 0 || x % 5 == 0; });
    
    int sum = std::accumulate(rng.begin(), rng.end(), 0);

    std::cout << sum << std::endl;

    return 0;
}
