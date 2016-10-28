import Debug

answer : Int
answer =
  Debug.log "answer"
    ([1..999]
      |> List.filter (\n -> n % 3 == 0 || n % 5 == 0)
      |> List.sum
    )
