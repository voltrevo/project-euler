import Debug


import Primes


answer : Int
answer =
  [1..20]
  |> List.map Primes.factorize
  |> List.foldl Primes.lcmFactors []
  |> Primes.defactorize
  |> Debug.log "answer"
