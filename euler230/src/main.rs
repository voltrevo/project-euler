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

fn main() {
    let q = get::<u128>();
    println!("read: {}", q);
}