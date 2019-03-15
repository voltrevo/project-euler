package main

import "fmt"

func main() {
    count := 0

    for n200 := 0; n200 <= 1; n200++ {
        for n100 := 0; n100 <= 2; n100++ {
            for n50 := 0; n50 <= 4; n50++ {
                for n20 := 0; n20 <= 10; n20++ {
                    for n10 := 0; n10 <= 20; n10++ {
                        for n5 := 0; n5 <= 40; n5++ {
                            for n2 := 0; n2 <= 100; n2++ {
                                if 200 * n200 + 100 * n100 + 50 * n50 + 20 * n20 + 10 * n10 + 5 * n5 + 2 * n2 <= 200 {
                                    count++
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    fmt.Println(count)
}
