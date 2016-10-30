module Big exposing (Big, fromInt, fromString, asString, add)


import Char
import String


type Big = Big (List Int)


addImpl : Int -> List Int -> List Int -> List Int
addImpl carry m n =
  case (m, n) of
    ([], []) ->
      if carry == 0 then
        []
      else
        [carry]
    _ ->
      let
        head = List.head >> Maybe.withDefault 0
        tail = List.tail >> Maybe.withDefault []
        headSum = carry + (head m) + (head n)
      in
        headSum % 10 :: addImpl (headSum // 10) (tail m) (tail n)


add : Big -> Big -> Big
add (Big m) (Big n) =
  Big (addImpl 0 m n)


toDigit : Char -> Int
toDigit c =
  (Char.toCode c) - (Char.toCode '0')


fromDigit : Int -> Char
fromDigit d =
  Char.fromCode ((Char.toCode '0') + d)


fromString : String -> Big
fromString = String.toList >> List.map toDigit >> List.reverse >> Big


fromInt : Int -> Big
fromInt n =
  let
    impl n =
      if n == 0 then
        []
      else
        n % 10 :: impl (n // 10)
  in
    Big (impl n)


asString : Big -> String
asString (Big list) =
  list
    |> List.reverse
    |> List.map fromDigit
    |> String.fromList
