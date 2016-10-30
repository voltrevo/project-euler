module Loop exposing (loop)


loop : state -> (state -> Bool) -> (state -> state) -> state
loop curr test iter =
  if test curr then
    loop (iter curr) test iter
  else
    curr
