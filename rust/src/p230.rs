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

fn solve(a: &str, b: &str, mut n: u128) -> char {
    let mut fib = (a.len() as u128, b.len() as u128);
    let mut term_no = 2;

    while fib.0 + fib.1 < n {
        fib = (fib.1, fib.0 + fib.1);
        term_no += 1;
    }

    loop {
        if n <= fib.0 {
            term_no -= 2;
            if term_no < 2 { break; }
            fib = (fib.1 - fib.0, fib.0);
            fib = (fib.1 - fib.0, fib.0);
        } else {
            term_no -= 1;
            n -= fib.0;
            if term_no < 2 { break; }
            fib = (fib.1 - fib.0, fib.0);
        }
    }

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

        panic!("Ran out of digits");
    }

    panic!("Unexpected term_no");
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