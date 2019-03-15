package main

import (
    "../common"
    "fmt"
    "log"
    "os"
    "sort"
)

func stringSum(s string) int {
    sum := 0

    for i := 0; i != len(s); i++ {
        sum += int(s[i]) - int('A') + 1
    }

    return sum
}

func main() {
    file, err := os.Open("./data/p22Names.txt")

    if err != nil {
        log.Fatal(err)
    }

    names := []string{}

    common.ReadLines(
        file,
        func(_ int, line string) {
            names = append(names, line)
        })

    sort.Strings(names)
    sum := 0

    for i, name := range(names) {
        sum += (i + 1) * stringSum(name)
    }

    fmt.Println(sum)
}
