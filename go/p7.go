package main

import "fmt"

import "../common"

func main() {
    count := 0
    common.FindPrimes(
        1000000,
        func(p int) {
            count++
            if count == 10001 {
                fmt.Println(p)
            }
        })
}
