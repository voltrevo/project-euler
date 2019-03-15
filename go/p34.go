package main

import "fmt"

func factorial(n int) int {
    product := 1

    for ; n >= 2; n-- {
        product *= n
    }

    return product
}

func factorialDigitSum(n int) int {
    sum := 0

    for n > 0 {
        sum += factorial(n % 10)
        n /= 10
    }

    return sum
}

func main() {
    sum := 0
    for i := 10; i != 2540160; i++ {
        if factorialDigitSum(i) == i {
            sum += i
        }
    }
    fmt.Println(sum)
}
