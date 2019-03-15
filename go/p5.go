package main

import "fmt"

func getPrimes() []int {
    return []int{2, 3, 5, 7, 11, 13, 17, 19}
}

func main() {
    primes := []int{2, 3, 5, 7, 11, 13, 17, 19}
    n := []int{0, 0, 0, 0, 0, 0, 0, 0}

    for i := 2; i <= 20; i++ {
        ii := i
        for idx, p := range primes {
            pow := 0
            for ii % p == 0 {
                ii /= p
                pow++
            }
            if pow > n[idx] {
                n[idx] = pow
            }
        }
    }

    nval := 1

    for idx, pow := range n {
        for i := 0; i != pow; i++ {
            nval *= primes[idx]
        }
    }

    fmt.Println(nval)
}
