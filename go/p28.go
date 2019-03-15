package main

import "fmt"

func main() {
    sum := 1

    nums := [...]int{1, 1, 1, 1}
    diffs := [...]int{2, 4, 6, 8}

    for i := 0; i != 500; i++ {
        for j := 0; j != len(nums); j++ {
            nums[j] += diffs[j]
            diffs[j] += 8
            sum += nums[j]
        }
    }

    fmt.Println(sum)
}
