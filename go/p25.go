package main

import (
    "fmt"
    "math/big"
)

func main() {
    threshold := big.NewInt(1)
    ten := big.NewInt(10)
    for i := 0; i != 999; i++ {
        threshold.Mul(threshold, ten)
    }

    fa := big.NewInt(1)
    fb := big.NewInt(1)

    i := 2

    for {
        fa.Add(fa, fb)
        i++

        if fa.Cmp(threshold) >= 0 {
            break
        }

        fb.Add(fa, fb)
        i++

        if fb.Cmp(threshold) >= 0 {
            break
        }
    }

    fmt.Println(i)
}
