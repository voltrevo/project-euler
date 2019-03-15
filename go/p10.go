package main

import "fmt"

import "../common"

func main() {
    sum := 0
    common.FindPrimes(
        2000000,
        func (p int) {
            sum += p
        })

    fmt.Println(sum)
}
