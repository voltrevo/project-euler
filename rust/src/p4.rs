pub fn calc() -> u32 {
    let mut largest = 0;

    for i in (100..999).rev() {
        for j in (100..999).rev() {
            let product = i * j;

            if product <= largest {
                break;
            }

            if is_palindrome(product) {
                largest = product;
            }
        }
    }

    return largest;
}

fn digits(mut n: u32) -> Vec<u8> {
    let mut res = vec![];

    while n > 0 {
        res.push((n % 10) as u8);
        n /= 10;
    }

    return res;
}

fn is_reversed<T: std::cmp::PartialEq>(arr: Vec<T>) -> bool {
    if arr.len() == 0 {
        return true;
    }

    let mut left = 0;
    let mut right = arr.len() - 1;

    while left < right {
        if arr[left] != arr[right] {
            return false;
        }

        left += 1;
        right -= 1;
    }

    return true;
}

fn is_palindrome(n: u32) -> bool {
    is_reversed(digits(n))
}