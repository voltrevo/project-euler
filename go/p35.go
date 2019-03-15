package main

import (
    "../common"
    "fmt"
)

func digitLen(n int) int {
    length := 0

    for n > 0 {
        n /= 10
        length++
    }

    return length
}

func rotateDigits(n, length int) int {
    last := n % 10
    n /= 10

    for i := 1; i != length; i++ {
        last *= 10
    }

    return last + n
}

func main() {
    primeFlags := [1000000]bool{}
    common.FindPrimes(
        1000000,
        func(p int) {
            primeFlags[p] = true
        })

    count := 0

    for i := 2; i != 1000000; i++ {
        if primeFlags[i] {
            length := digitLen(i)
            j := i
            for {
                j = rotateDigits(j, length)

                if j == i {
                    count++
                    break
                }

                if !primeFlags[j] {
                    break
                }
            }
        }
    }

    fmt.Println(count)
}
