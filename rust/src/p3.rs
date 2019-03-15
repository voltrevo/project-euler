use super::util;

pub fn calc() -> i64 {
    let mut n = 600851475143;

    let mut p_large = 0;
    let mut p = 2;

    while n != 1 {
        while n % p == 0 {
            n /= p;
            p_large = p;
        }

        p = util::next_prime(p);
    }

    return p_large;
}
