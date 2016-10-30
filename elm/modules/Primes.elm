module Primes exposing (start, increment)


import Array


import ArrayExtras
import MaybeExtras exposing (unmaybe)
import Loop exposing (loop)


start : Array.Array Int
start = Array.fromList [2]


increment : Array.Array Int -> Array.Array Int
increment primes =
  let
    start primes =
      (primes, primes |> ArrayExtras.last |> unmaybe |> (+) 1)
    testIPrime (primes, i) =
      let
        head = primes |> Array.get 0 |> unmaybe
      in
        if head * head > i then
          True
        else if i % head == 0 then
          False
        else
          testIPrime (ArrayExtras.tail primes, i)
    next (primes, i) =
      (primes, i + 1)
  in
    (loop
      (start primes)
      (testIPrime >> not)
      next
    )
      |> \(primes, p) -> Array.push p primes