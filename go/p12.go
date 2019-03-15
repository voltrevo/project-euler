package main

import (
    "fmt"
    "../common"
)

func numFactors(n int) int {
    primeFactors := common.PrimeFactors(n)
    product := 1
    for _, factor := range primeFactors {
        product *= factor.N + 1
    }

    return product
}

func main() {
    sum := 0
    for i := 1; ; i++ {
        sum += i
        if numFactors(sum) > 500 {
            fmt.Println(sum)
            break
        }
    }
}
