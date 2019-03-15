package main

import (
    "fmt"
    "time"
)

func main() {

    count := 0

    for year := 1901; year != 2001; year++ {
        for month := time.January; month <= time.December; month++ {
            if time.Date(year, month, 1, 0, 0, 0, 0, time.UTC).Weekday() == time.Sunday {
                count++
            }
        }
    }

    fmt.Println(count)
}
