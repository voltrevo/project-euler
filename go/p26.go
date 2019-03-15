package main

import "fmt"

func decimalLen(n int) int {
    rem1 := 1
    rem2 := 1

    for {
        rem1 = 10 * rem1 % n
        rem2 = 100 * rem2 % n

        if rem1 == rem2 {
            break
        }
    }

    len := 0
    for {
        rem1 = 10 * rem1 % n
        len++

        if rem1 == rem2 {
            break
        }
    }

    return len
}

func main() {
    longestLen := 0
    longestDivisor := 0

    for divisor := 1; divisor != 1000; divisor++ {
        length := decimalLen(divisor)

        if length > longestLen {
            longestLen = length
            longestDivisor = divisor
        }
    }

    fmt.Println(longestDivisor)
}
