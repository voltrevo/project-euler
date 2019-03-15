package main

import "fmt"

func collatzLength(n int) int {
    length := 1
    for n != 1 {
        if n % 2 == 0 {
            n /= 2
        } else {
            n = 3 * n + 1
        }
        length++
    }

    return length
}

func cachedCollatzLength(n int, cache map[int]int) int {
    if n == 1 {
        return 1
    }

    if length, found := cache[n]; found {
        return length
    }

    length := 0

    if n % 2 == 0 {
        length = 1 + cachedCollatzLength(n / 2, cache)
    } else {
        length = 1 + cachedCollatzLength(3 * n + 1, cache)
    }

    cache[n] = length
    return length
}

func main() {
    longest := 0
    longestNum := 0
    //cache := map[int]int{}
    for i := 1; i != 1000000; i++ {
        //length := cachedCollatzLength(i, cache)
        length := collatzLength(i)
        if length > longest {
            longest = length
            longestNum = i
        }
    }

    fmt.Println(longestNum)
}
