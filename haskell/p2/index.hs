module Main where

  fibPair n =
    if n == 0 then
      (1, 0)
    else
      let prev = fibPair (n - 1)
      in (snd prev, fst prev + snd prev)

  fib n =
    snd (fibPair n)

  main = print (
    sum [fib n | n <- [2..1000], fib n <= 4000000, fib n `mod` 2 == 0])
