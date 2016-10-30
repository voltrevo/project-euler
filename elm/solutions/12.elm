import Debug


import Loop exposing (loop)
import Primes exposing (divisorCount)


answer : Int
answer =
  (loop
    (1, 1)
    (snd >> divisorCount >> flip (>) 500 >> not)
    (\(i, tri) -> (i + 1, tri + i + 1))
  )
    |> snd
    |> Debug.log "answer"
