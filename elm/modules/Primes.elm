module Primes exposing
  ( start
  , increment
  , factorize
  , factorizeFloat
  , defactorize
  , hcfFactors
  , lcmFactors
  , hcf
  , lcm
  , divisorCount)


import Array


import ArrayExtras
import MaybeExtras exposing (unmaybe)
import ListExtras
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


factorizeGeneral
  : (number -> Int -> number)
  -> (number -> Int -> number)
  -> number
  -> List (Int, Int)
factorizeGeneral mod div n =
  (loop
    { primes = start
    , factors = []
    , rem = n
    }
    (.rem >> (/=) 1)
    (\{primes, factors, rem} ->
      let p = ArrayExtras.last primes |> unmaybe
      in if mod rem p == 0 then
        { primes = primes
        , factors = p :: factors
        , rem = div rem p
        }
      else
        { primes = increment primes
        , factors = factors
        , rem = rem
        }
    )
  )
    |> .factors
    |> List.reverse
    |> ListExtras.uniqCounts


factorize : Int -> List (Int, Int)
factorize = factorizeGeneral (%) (//)


factorizeFloat : Float -> List (Int, Int)
factorizeFloat =
  let
    mod =
      (\n -> \d ->
        let fd = toFloat d
        in (n / fd - toFloat (floor (n / fd))) * fd
          |> round
          |> toFloat
      )
    div = \n -> \d -> n / (toFloat d) |> floor |> toFloat
  in
    factorizeGeneral mod div


defactorize : List (Int, Int) -> Int
defactorize =
  List.map (\(prime, power) -> prime ^ power)
  >> List.foldl (*) 1


hcfFactors
  : List (comparable, comparable)
  -> List (comparable, comparable)
  -> List (comparable', comparable)
hcfFactors leftFactors rightFactors =
  case (leftFactors, rightFactors) of
    ([], []) ->
      []
    (leftHead :: leftTail, []) ->
      []
    ([], rightHead :: rightTail) ->
      []
    ((leftPrime, leftPower) :: leftTail, (rightPrime, rightPower) :: rightTail) ->
      case compare leftPrime rightPrime of
        LT ->
          hcfFactors leftTail rightFactors
        GT ->
          hcfFactors leftFactors rightTail
        EQ ->
          (leftPower, min leftPower rightPower) :: hcfFactors leftTail rightTail


lcmFactors
  : List (comparable, comparable)
  -> List (comparable, comparable)
  -> List (comparable', comparable)
lcmFactors leftFactors rightFactors =
  case (leftFactors, rightFactors) of
    ([], []) ->
      []
    (leftHead :: leftTail, []) ->
      leftFactors
    ([], rightHead :: rightTail) ->
      rightFactors
    ((leftPrime, leftPower) :: leftTail, (rightPrime, rightPower) :: rightTail) ->
      case compare leftPrime rightPrime of
        LT ->
          (leftPrime, leftPower) :: lcmFactors leftTail rightFactors
        GT ->
          (rightPrime, rightPower) :: lcmFactors leftFactors rightTail
        EQ ->
          (leftPrime, max leftPower rightPower) :: lcmFactors leftTail rightTail


hcf : Int -> Int -> Int
hcf m n =
  hcfFactors (factorize m) (factorize n)
  |> defactorize


lcm : Int -> Int -> Int
lcm m n =
  lcmFactors (factorize m) (factorize n)
  |> defactorize


divisorCount : Int -> Int
divisorCount n =
  factorize n
    |> List.map (snd >> (+) 1)
    |> List.foldl (*) 1
