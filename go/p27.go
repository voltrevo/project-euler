package main

import (
    "../common"
    "fmt"
)

func main() {
    primeFlags := [1000000]bool{}

    common.FindPrimes(
        1000000,
        func(p int) {
            primeFlags[p] = true
        })

    isPrime := func(n int) bool {
        if n < 0 || n >= 1000000 {
            return false
        }

        return primeFlags[n]
    }

    maxLength := 0
    maxA := 0
    maxB := 0

    for a := -1000; a <= 1000; a++ {
        for b := -1000; b <= 1000; b++ {
            n := 0
            for isPrime(n * n + a * n + b) {
                n++
            }

            if n > maxLength {
                maxLength = n
                maxA = a
                maxB = b
            }
        }
    }

    fmt.Println(maxA * maxB)
}
