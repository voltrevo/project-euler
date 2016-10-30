import Array
import Debug


import ArrayExtras
import Loop exposing (loop)
import MaybeExtras exposing (unmaybe)
import Primes


answer : Int
answer =
  (loop
    Primes.start
    (Array.length >> flip (<) 10001)
    Primes.increment
  )
    |> ArrayExtras.last
    |> unmaybe
    |> Debug.log "answer"
