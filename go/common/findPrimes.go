package common

func FindPrimes(max int, cb func(int)) {
    flags := make([]bool, max + 1)
    for i := 2; i < len(flags); i++ {
        flags[i] = true
    }

    i := 2
    for {
        for i <= max && !flags[i] {
            i++
        }
        cb(i)

        if i * i > max {
            i++
            break
        }

        mark := 2 * i
        for mark <= max {
            flags[mark] = false
            mark += i
        }

        i++
    }

    for i <= max {
        if flags[i] {
            cb(i)
        }

        i++
    }
}
