#include <vector>
#include <iostream>

#include "util/generator.hpp"

generator<int> get_digits(int n);
bool is_palindrome(int n);

int main() {
    int biggest = 0;

    for (int a = 999; a >= 100; a--) {
        if (a * a < biggest) {
            break;
        }

        for (int b = a; b >= 100; b--) {
            int ab = a * b;

            if (ab < biggest) {
                break;
            }

            if (is_palindrome(ab)) {
                biggest = ab;
                break;
            }
        }
    }

    std::cout << biggest << std::endl;
}

generator<int> get_digits(int n) {
    while (n > 0) {
        co_yield n % 10;
        n /= 10;
    }
}

bool is_palindrome(int n) {
    auto digits = std::vector(std::from_range, get_digits(n));
    
    int left = 0;
    int right = digits.size() - 1;

    while (left < right) {
        if (digits[left] != digits[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
