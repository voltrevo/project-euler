package common

import "math"

func PrimeFactors(n int) []struct{P int; N int} {

    factors := []struct{P int; N int}{}

    FindPrimes(
        int(math.Sqrt(float64(n))),
        func(p int) {

            if n % p == 0 {
                factor := struct{P int; N int}{p, 1}
                n /= p

                for n % p == 0 {
                    factor.N++
                    n /= p
                }

                factors = append(factors, factor)
            }
        })

    if n != 1 {
        factors = append(factors, struct{P int; N int}{n, 1})
    }

    return factors
}
