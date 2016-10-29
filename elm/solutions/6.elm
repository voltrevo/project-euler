import Debug

answer : Int
answer =
  let
    sumSq = [1..100] |> List.map (\i -> i * i) |> List.sum
    sqSum = [1..100] |> List.sum |> (\sum -> sum * sum)
  in
    sqSum - sumSq
    |> Debug.log "answer"
