package main

import "fmt"

func getDigits(n, b int) []int {
    digits := []int{}
    for n > 0 {
        digits = append(digits, n % b)
        n /= b
    }
    return digits
}

func isPalindrome(digits []int) bool {
    left := 0
    right := len(digits) - 1

    for left < right {
        if digits[left] != digits[right] {
            return false
        }

        left++
        right--
    }

    return true
}

func main() {
    sum := 0
    for i := 1; i != 1000000; i++ {
        if isPalindrome(getDigits(i, 10)) && isPalindrome(getDigits(i, 2)) {
            sum += i
        }
    }
    fmt.Println(sum)
}
