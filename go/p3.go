package main

import "fmt"

func main() {
    //n := 600851475143
    n := 18
    i := 2

    for {
        for n % i == 0 {
            n /= i
        }

        if i * i > n {
            break
        }

        i++
    }

    if n != 1 {
        fmt.Println(n)
    } else {
        fmt.Println(i)
    }
}
