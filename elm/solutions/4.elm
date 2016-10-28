import Debug


loop : state -> (state -> Bool) -> (state -> state) -> state
loop curr test iter =
  if test curr then
    loop (iter curr) test iter
  else
    curr


toDigitList : Int -> List Int
toDigitList n =
  (loop
    { digits = []
    , rem = n
    }
    (\state -> (.rem state) /= 0)
    (\state ->
      { digits = (.rem state % 10) :: (.digits state)
      , rem = (.rem state) // 10
      }
    )
  )
    |> .digits


isPalindrome : Int -> Bool
isPalindrome n =
  let
    digits = toDigitList n
  in
    digits == List.reverse digits


listProduct : List a -> List b -> List (a, b)
listProduct l1 l2 =
  (List.map
    (\i ->
      List.map (\j -> (i, j)) l2
    )
    l1
  )
    |> List.concat


answer : Maybe Int
answer =
  listProduct [100..999] [100..999]
  |> List.map (\(i, j) -> i * j)
  |> List.filter isPalindrome
  |> List.maximum
  |> Debug.log "answer"
