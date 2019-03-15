package main

import "fmt"

func combinations(n int, r int) int {
    if n - r < r {
        r = n - r
    }

    nextDivisor := 2
    result := 1
    for i := n; i != n - r; i-- {
        result *= i

        for nextDivisor <= r && result % nextDivisor == 0 {
            result /= nextDivisor
            nextDivisor++
        }
    }

    return result
}

func main() {
    fmt.Println(combinations(40, 20))
}
