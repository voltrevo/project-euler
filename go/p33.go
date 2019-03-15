package main

import (
    "../common"
    "fmt"
)

func sillyCancel(f common.Fraction) common.Fraction {
    if f.N / 10 == f.D / 10 {
        return common.Fraction{f.N % 10, f.D % 10}
    }

    if f.N % 10 == f.D % 10 && f.N % 10 != 0 { // Excluding trivial examples here
        return common.Fraction{f.N / 10, f.D / 10}
    }

    if f.N / 10 == f.D % 10 {
        return common.Fraction{f.N % 10, f.D / 10}
    }

    if f.N % 10 == f.D / 10 {
        return common.Fraction{f.N / 10, f.D % 10}
    }

    return f
}

func main() {
    sillies := []common.Fraction{}

    f := common.Fraction{}
    for f.N = 10; f.N != 100; f.N++ {
        for f.D = f.N + 1; f.D < 100; f.D++ {
            if f != sillyCancel(f) && common.FractionsEqual(f, sillyCancel(f)) {
                sillies = append(sillies, f.Simplify())
            }
        }
    }

    product := common.Fraction{1, 1}
    for _, s := range sillies {
        product.N *= s.N
        product.D *= s.D
    }

    fmt.Println(product.Simplify().D)
}
