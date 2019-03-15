pub fn calc() -> i64 {
    let mut n = 600851475143;

    let mut p_large = 0;
    let mut p = 2;

    while n != 1 {
        while n % p == 0 {
            n /= p;
            p_large = p;
        }

        p = next_prime(p);
    }

    return p_large;
}

fn next_prime(mut p: i64) -> i64 {
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