package common

func FactorSum(n int) int {

	primeFactors := PrimeFactors(n)

	sum := 0

	powers := make([]int, len(primeFactors), len(primeFactors))
	factor := 1

	sum += factor

	for {
		i := 0
		for {

			if i >= len(powers) {
				break
			}

			if powers[i] != primeFactors[i].N {
				powers[i]++
				factor *= primeFactors[i].P
				break
			} else {
				for ; powers[i] != 0; powers[i]-- {
					factor /= primeFactors[i].P
				}

				i++
			}
		}

		if i >= len(powers) {
			break
		}

		sum += factor
	}

	return sum - n
}
