pub fn next_prime(mut p: i64) -> i64 {
    if p == 2 {
        return 3;
    }

    p += 2;
    let mut i = 3;
    
    while i * i <= p {
        if p % i == 0 {
            i = 3;
            p += 2;
        } else {
            i += 2;
        }
    }

    return p;
}