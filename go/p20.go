package main

import (
    "fmt"
    "math/big"
    "strconv"
)

func main() {

    n := big.Int{}
    n.MulRange(2, 100)

    sum := 0

    for _, c := range n.String() {
        d, _ := strconv.Atoi(string(c))
        sum += d
    }

    fmt.Println(sum)
}
