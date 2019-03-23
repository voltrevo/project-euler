use std::io;

fn get<T>() -> T where
  T: std::str::FromStr,
  <T as std::str::FromStr>::Err: std::fmt::Debug
{
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("failed to read from stdin");

    let trimmed = input_text.trim();

    return trimmed.parse::<T>().unwrap();
}

fn solve(a: &str, b: &str, n: u128) -> char {
    return find_digit(a, b, find_term_no(a, b, n), n);
}

fn find_term_no(a: &str, b: &str, n: u128) -> usize {
    let mut fib = (a.len() as u128, b.len() as u128);
    let mut i = 2;

    while fib.0 + fib.1 < n {
        fib = (fib.1, fib.0 + fib.1);
        i += 1;
    }

    return i;
}

fn find_digit(a: &str, b: &str, term_no: usize, n: u128) -> char {
    if term_no == 0 {
        for (k, c) in a.chars().enumerate() {
            if (k + 1) as u128 == n {
                return c;
            }
        }

        panic!("Ran out of digits")
    }

    if term_no == 1 {
        for (k, c) in b.chars().enumerate() {
            if (k + 1) as u128 == n {
                return c;
            }
        }

        panic!("Ran out of digits")
    }

    let mut fib = (a.len() as u128, b.len() as u128);
    let mut i = 2;

    while i < term_no {
        fib = (fib.1, fib.0 + fib.1);
        i += 1;
    }

    if n <= fib.0 {
        return find_digit(a, b, term_no - 2, n);
    }

    return find_digit(a, b, term_no - 1, n - fib.0);
}

fn main() {
    let q = get::<u128>();

    for _ in 0..q {
        let line = get::<String>();
        let mut a = "";
        let mut b = "";
        let mut n = 0;

        for (i, word) in line.split_whitespace().enumerate() {
            match i {
                0 => a = word,
                1 => b = word,
                2 => n = word.parse::<u128>().unwrap(),
                _ => panic!("Too many words"),
            }
        }

        println!("{}", solve(a, b, n));
    }
}