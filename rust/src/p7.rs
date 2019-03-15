use super::util;

pub fn calc() -> i64 {
    let mut p = 2;

    for _ in 0..10000 {
        p = util::next_prime(p);
    }

    return p;
}