use std::io;

fn get<T>() -> T
  where T: std::str::FromStr
{
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("failed to read from stdin");

    let trimmed = input_text.trim();

    return match trimmed.parse::<T>() {
        Ok(i) => i,
        Err(..) => panic!("Parse failure"),
    };
}

fn main() {
    let q = get::<u128>();
    println!("read: {}", q);
}