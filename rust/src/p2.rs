pub fn calc() -> i32 {
    let mut fib = (1, 1);
    let mut sum = 0;

    while fib.1 < 4000000 {
        if fib.1 % 2 == 0 {
            sum += fib.1;
        }

        fib = (fib.1, fib.0 + fib.1);
    }

    return sum;
}