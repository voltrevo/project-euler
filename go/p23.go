package main

import (
    "../common"
    "fmt"
)

func isAbundant(n int) bool {
    return common.FactorSum(n) > n
}

func main() {
    isSumOf2Abundants := [28123]bool{}
    abundants := []int{}

    for i := 1; i != 28123; i++ {
        if (isAbundant(i)) {
            abundants = append(abundants, i)
        }
    }

    for i := 0; i < len(abundants); i++ {
        for j := i; abundants[i] + abundants[j] < 28123 && j < len(abundants); j++ {
            isSumOf2Abundants[abundants[i] + abundants[j]] = true
        }
    }

    sum := 0
    for i := 0; i != 28123; i++ {
        if !isSumOf2Abundants[i] {
            sum += i
        }
    }

    fmt.Println(sum)
}
