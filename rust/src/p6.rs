pub fn calc() -> u32 {
    let mut sq_sum = 0;
    let mut sum_sq = 0;

    for i in 1..101 {
        sq_sum += i * i;
        sum_sq += i;
    }

    return sum_sq * sum_sq - sq_sum;
}