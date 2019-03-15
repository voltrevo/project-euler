package main

import "fmt"

func basicPow(n, pow int) int {
    product := 1

    for i := 0; i != pow; i++ {
        product *= n
    }

    return product
}

func digitPowSum(n, pow int) int {
    sum := 0
    for n > 0 {
        sum += basicPow(n % 10, pow)
        n /= 10
    }
    return sum
}

func main() {
    sum := 0
    for n := 2; n != 295245; n++ {
        if n == digitPowSum(n, 5) {
            sum += n
        }
    }
    fmt.Println(sum)
}
