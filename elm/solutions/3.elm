import Debug


loop : state -> (state -> Bool) -> (state -> state) -> state
loop curr test iter =
  if test curr then
    loop (iter curr) test iter
  else
    curr


floatMod : Float -> Float -> Float
floatMod a b =
  floor(a) % floor(b) |> toFloat


answer : Maybe Float
answer =
  (loop
    { n = 600851475143
    , factors = []
    , i = 2
    }
    (.n >> (/=) 1)
    (\{n, factors, i} ->
      if floatMod n i == 0 then
        { n = n / i
        , factors = i :: factors
        , i = i
        }
      else
        { n = n
        , factors = factors
        , i = i + 1
        }
    )
  )
    |> .factors
    |> List.head
    |> Debug.log "answer"
