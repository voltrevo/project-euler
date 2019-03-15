package main

import "fmt"

func isPalindrome(n int) bool {
    d := make([]int, 0)

    for n > 0 {
        d = append(d, n % 10)
        n /= 10
    }

    left := 0
    right := len(d) - 1

    for left < right {
        if d[left] != d[right] {
            return false
        }

        left++
        right--
    }

    return true
}

func main() {
    largest := 0

    for i := 100; i <= 999; i++ {
        for j := 100; j <= 999; j++ {
            product := i * j
            if product > largest && isPalindrome(product) {
                largest = product
            }
        }
    }

    fmt.Println(largest)
}
