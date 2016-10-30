import Array
import Debug


import ArrayExtras
import Loop exposing (loop)
import MaybeExtras exposing (unmaybe)
import Primes


answer : Float
answer =
  (loop
    Primes.start
    (ArrayExtras.last >> unmaybe >> flip (<) 2000000)
    Primes.increment
  )
    |> (\arr -> Array.slice 0 ((Array.length arr) - 1) arr)
    |> Array.map toFloat
    |> Array.foldl (+) 0
    |> Debug.log "answer"
