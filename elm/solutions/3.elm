import Debug


import Primes
import MaybeExtras exposing (passMaybe1)


answer : Maybe Int
answer =
  Primes.factorizeFloat 600851475143
  |> List.reverse
  |> List.head
  |> passMaybe1 fst
  |> Debug.log "answer"
