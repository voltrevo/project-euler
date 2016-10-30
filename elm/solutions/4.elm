import Debug


import ListExtras


toDigitList : Int -> List Int
toDigitList n =
  let
    digit = n % 10
    rem = n // 10
  in
    digit :: if rem == 0 then
      []
    else
      toDigitList rem


isPalindrome : Int -> Bool
isPalindrome n =
  let
    digits = toDigitList n
  in
    digits == List.reverse digits


answer : Maybe Int
answer =
  ListExtras.product [100..999] [100..999]
  |> List.map (\(i, j) -> i * j)
  |> List.filter isPalindrome
  |> List.maximum
  |> Debug.log "answer"
