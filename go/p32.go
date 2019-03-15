package main

import "fmt"

func processDigits(n int, cb func(int)) {
    for n > 0 {
        cb(n % 10)
        n /= 10
    }
}

func isPandigital(a, b, ab int) bool {
    digitFlags := [10]bool{}

    totalCount := 0
    uniqueCount := 0

    cb := func(d int) {
        totalCount++
        if !digitFlags[d] {
            digitFlags[d] = true
            uniqueCount++
        }
    }

    processDigits(a, cb)
    processDigits(b, cb)
    processDigits(ab, cb)

    return (
        !digitFlags[0] &&
        totalCount == 9 &&
        uniqueCount == 9)
}

func main() {
    products := map[int]struct{}{}
    for a := 1; a < 10000; a++ {
        for b := 1; b < 10000; b++ {
            if isPandigital(a, b, a * b) {
                products[a * b] = struct{}{}
            }
        }
    }

    sum := 0
    for k, _ := range products {
        sum += k
    }

    fmt.Println(sum)
}
