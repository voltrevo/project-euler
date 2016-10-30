import Array
import Debug


import Loop exposing (loop)


arrayLast : Array.Array a -> Maybe a
arrayLast array =
  Array.get ((Array.length array) - 1) array


arrayGetFrom : Int -> Array.Array a -> Array.Array a
arrayGetFrom i array =
  Array.slice i (array |> Array.length) array


arrayTail : Array.Array a -> Array.Array a
arrayTail array =
  arrayGetFrom 1 array


unmaybe : Maybe a -> a
unmaybe x =
  case x of
    Nothing ->
      let
        dummy = Debug.crash "Nothing passed to unmaybe"
      in
        unmaybe x
    Just y ->
      y


incrementPrimes : Array.Array Int -> Array.Array Int
incrementPrimes primes =
  let
    start primes =
      (primes, primes |> arrayLast |> unmaybe |> (+) 1)
    testIPrime (primes, i) =
      let
        head = primes |> Array.get 0 |> unmaybe
      in
        if head * head > i then
          True
        else if i % head == 0 then
          False
        else
          testIPrime (arrayTail primes, i)
    next (primes, i) =
      (primes, i + 1)
  in
    (loop
      (start primes)
      (testIPrime >> not)
      next
    )
      |> \(primes, p) -> Array.push p primes


answer : Float
answer =
  (loop
    (Array.fromList [2])
    (arrayLast >> unmaybe >> flip (<) 2000000)
    incrementPrimes
  )
    |> (\arr -> Array.slice 0 ((Array.length arr) - 1) arr)
    |> Array.map toFloat
    |> Array.foldl (+) 0
    |> Debug.log "answer"
