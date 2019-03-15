package main

import (
    "fmt"
    "../common"
)

func main() {

    sum := 0

    for i := 2; i != 10000; i++ {

        first := common.FactorSum(i)
        second := common.FactorSum(first)

        if first != i && second == i {
            sum += i
        }
    }

    fmt.Println(sum)
}
