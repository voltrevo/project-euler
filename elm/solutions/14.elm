import Debug


collatzStep : Float -> Float
collatzStep n =
  let
    mod =
      (\n -> \d ->
        let fd = toFloat d
        in (n / fd - toFloat (floor (n / fd))) * fd
          |> round
          |> toFloat
      )
    div = \n -> \d -> n / (toFloat d) |> floor |> toFloat
  in
    if mod n 2 == 0 then
      div n 2
    else
      3 * n + 1


collatzLength : Float -> Int
collatzLength n =
  let
    impl (preLen, n) =
      if n == 1 then
        (preLen + 1, 1)
      else
        impl (preLen + 1, collatzStep n)
  in
    impl (0, n) |> fst


answer : Float
answer =
  [1..1000000]
    |> List.map (\n -> (n, collatzLength n))
    |> List.foldl
      (\(bestN, bestLen) -> \(n, len) ->
        if len > bestLen then
          (n, len)
        else
          (bestN, bestLen)
      )
      (0, 0)
    |> fst
    |> Debug.log "answer"
