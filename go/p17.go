package main

import "fmt"

    func numAsWords(n int) string {

        units := [20]string{
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine",
            "ten",
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen",
            "sixteen",
            "seventeen",
            "eighteen",
            "nineteen",
        }

        tens := [10]string{
            // Dummies here just to make the indexes match better
            "",
            "",

            // Actual values
            "twenty",
            "thirty",
            "forty",
            "fifty",
            "sixty",
            "seventy",
            "eighty",
            "ninety",
        }

        if n < 20 {
            return units[n]
        }

        if n < 100 {
            if n % 10 == 0 {
                return tens[n / 10]
            }

            return tens[n / 10] + "-" + units[n % 10]
        }

        if n < 1000 {
            if n % 100 == 0 {
                return units[n / 100] + " hundred"
            }

            return units[n / 100] + " hundred and " + numAsWords(n % 100)
        }

        return "one thousand"
    }

func main() {

    count := 0

    for i := 1; i <= 1000; i++ {
        for _, c := range numAsWords(i) {
            if c != ' ' && c != '-' {
                count++
            }
        }
    }

    fmt.Println(count)
}
