package main

import "fmt"

func main() {
    sum := 0
    sqSum := 0

    for i := 1; i <= 100; i++ {
        sum += i
        sqSum += i * i
    }

    fmt.Println(sum * sum - sqSum)
}
