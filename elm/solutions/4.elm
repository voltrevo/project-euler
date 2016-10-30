import Debug


import Loop exposing (loop)
import ListExtras


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


answer : Maybe Int
answer =
  ListExtras.product [100..999] [100..999]
  |> List.map (\(i, j) -> i * j)
  |> List.filter isPalindrome
  |> List.maximum
  |> Debug.log "answer"
