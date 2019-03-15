pub fn calc() -> u32 {
    let mut n = 1;

    for i in 2..20 {
        n = lcm(n, i);
    }

    return n;
}

fn lcm(a: u32, b: u32) -> u32 {
    a / gcd(a, b) * b
}

fn gcd(mut a: u32, mut b: u32) -> u32 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }

    return a;
}