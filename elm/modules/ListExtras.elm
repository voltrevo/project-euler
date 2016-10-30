module ListExtras exposing (product, tails, window)


product : List a -> List b -> List (a, b)
product l1 l2 =
  (List.map
    (\i ->
      List.map (\j -> (i, j)) l2
    )
    l1
  )
    |> List.concat


tails : List a -> List (List a)
tails list =
  let
    loop (oldListMaybe, newList) =
      case oldListMaybe of
        Nothing ->
          newList
        Just oldList ->
          loop (List.tail oldList, oldList :: newList)
  in
    loop (Just list, [])


window : Int -> List a -> List (List a)
window size list =
  list
  |> tails
  |> List.map (List.take size)
  |> List.filter (List.length >> ((==) size))
