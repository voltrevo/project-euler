import Debug


answer : Maybe Int
answer =
  [1..1000]
  |> List.map (\a -> List.map (\b -> (a, b, 1000 - a - b)) [a..1000])
  |> List.concat
  |> List.filter (\(a, b, c) -> a * a + b * b == c * c)
  |> List.map (\(a, b, c) -> a * b * c)
  |> List.head
  |> Debug.log "answer"
