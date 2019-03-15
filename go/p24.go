package main

import "fmt"

func factorial(n int) int {
    product := 1

    for i := 2; i <= n; i++ {
        product *= i
    }

    return product
}

func permute(digits []int, n int) {
    if n == 0 {
        return
    }

    product := 1

    i := 2
    for {
        product *= i

        if product > n {
            product /= i
            i--
            break
        }

        i++
    }

    shift := n / product
    leftover := n - shift * product

    liftedNum := digits[len(digits) - 1 - i + shift]
    for j := len(digits) - 1 - i + shift; j > len(digits) - 1 - i; j-- {
        digits[j] = digits[j - 1]
    }

    digits[len(digits) - 1 - i] = liftedNum

    permute(digits[len(digits) - i:], leftover)
}

func main() {
    nums := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    permute(nums, 999999)
    fmt.Println(nums)
}
