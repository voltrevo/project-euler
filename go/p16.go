package main

import (
    "fmt"
    "math/big"
    "strconv"
)

func main() {
    n := big.Int{}
    n.SetString("1", 10)

    for i := 0; i != 1000; i++ {
        n.Add(&n, &n)
    }

    s := n.String()
    sum := 0

    for _, c := range s {
        d, _ := strconv.Atoi(string(c))
        sum += d
    }

    fmt.Println(sum)
}
