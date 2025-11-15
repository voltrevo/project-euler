#include <ranges>
#include <iostream>

#include "util/factorize.hpp"
#include "util/fold_left.hpp"

generator<int> join_factorize_lcm(generator<int> a, generator<int> b);

int main() {
    auto combined_lcm = std::views::iota(1, 21)
        | std::views::transform(factorize)
        | fold_left(factorize(1), join_factorize_lcm)
        | fold_left(1, std::multiplies<int>{});

    std::cout << combined_lcm << std::endl;
}

generator<int> join_factorize_lcm(generator<int> a, generator<int> b) {
    auto a_iter = a.begin();
    auto a_end = a.end();

    auto b_iter = b.begin();
    auto b_end = b.end();

    while (true) {
        while (*a_iter == *b_iter && a_iter != a_end && b_iter != b_end) {
            co_yield *a_iter;
            a_iter++;
            b_iter++;
        }

        if (a_iter == a_end) {
            while (b_iter != b_end) {
                co_yield *b_iter;
                b_iter++;
            }

            co_return;
        }

        if (b_iter == b_end) {
            while (a_iter != a_end) {
                co_yield *a_iter;
                a_iter++;
            }

            co_return;
        }

        if (*a_iter < *b_iter) {
            do {
                co_yield *a_iter;
                a_iter++;
            } while (a_iter != a_end && *a_iter < *b_iter);
        } else /* (*b_iter < *a_iter) */ {
            do {
                co_yield *b_iter;
                b_iter++;
            } while (b_iter != b_end && *b_iter < *a_iter);
        }
    }
}
