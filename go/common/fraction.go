package common

type Fraction struct{N, D int}

func minInt(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func (f Fraction) Simplify() Fraction {
    if f.N == 0 {
        return Fraction{0, 1}
    }

    if f.D == 0 {
        return Fraction{1, 0}
    }

    min := minInt(f.N, f.D)
    factors := PrimeFactors(min)

    for _, factor := range factors {
        for f.N % factor.P == 0 && f.D % factor.P == 0 {
            f.N /= factor.P
            f.D /= factor.P
        }
    }

    return f
}

func FractionsEqual(f Fraction, g Fraction) bool {
    return f.Simplify() == g.Simplify()
}
