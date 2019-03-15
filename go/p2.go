package main

import "fmt"

func main() {

	f := 2
	f_last := 1

	sum := 0

	for {
		if f%2 == 0 {
			sum += f
		}

		f, f_last = f+f_last, f

		if f > 4000000 {
			break
		}
	}

	fmt.Println(sum)
}
