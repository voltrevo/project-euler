import Debug


import Big


double : Big.Big -> Big.Big
double b = Big.add b b


answer : Int
answer =
  [0..999]
    |> List.foldl (\_ -> \b -> double b) (Big.fromString "1")
    |> Big.asDigits
    |> List.foldl (+) 0
    |> Debug.log "answer"
