package main

import (
    "../common"
    "fmt"
)

func main() {
    nums := map[string]struct{}{}

    for a := 2; a <= 100; a++ {
        for b := 2; b <= 100; b++ {
            factors := common.PrimeFactors(a)

            for i := 0; i != len(factors); i++ {
                factors[i].N *= b
            }

            nums[fmt.Sprint(factors)] = struct{}{}
        }
    }

    fmt.Println(len(nums))
}
