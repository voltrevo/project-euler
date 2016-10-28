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
    (\state -> (.n state) /= 1)
    (\state ->
      if floatMod (.n state) (.i state) == 0 then
        { n = (.n state) / (.i state)
        , factors = (.i state) :: (.factors state)
        , i = .i state
        }
      else
        { state | i = (.i state) + 1 }
    )
  )
    |> .factors
    |> List.head
    |> Debug.log "answer"
