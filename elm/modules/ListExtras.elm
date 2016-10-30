module ListExtras exposing (product, tails, window, uniq, uniqCounts)


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


uniq : List a -> List a
uniq list =
  let
    drop : a -> List a -> List a
    drop member list =
      case list of
        [] ->
          []
        head :: tail ->
          if head == member then
            drop member tail
          else
            list
  in
    case list of
      [] ->
        []
      head :: tail ->
        head :: uniq (drop head tail)


countHead : (a, Int) -> List a -> ((a, Int), List a)
countHead (member, count) list =
  case list of
    [] ->
      ((member, count), [])
    head :: tail ->
      if head == member then
        countHead (member, count + 1) tail
      else
        ((member, count), list)


uniqCounts : List a -> List (a, Int)
uniqCounts list =
  let
    countHead : (a, Int) -> List a -> ((a, Int), List a)
    countHead (member, count) list =
      case list of
        [] ->
          ((member, count), [])
        head :: tail ->
          if head == member then
            countHead (member, count + 1) tail
          else
            ((member, count), list)
  in
    case list of
      [] ->
        []
      head :: tail ->
        let ((member, count), rest) = countHead (head, 0) list
        in (member, count) :: uniqCounts rest

