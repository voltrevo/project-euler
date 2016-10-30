module MaybeExtras exposing (unmaybe, passMaybe1, passMaybe2)


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


passMaybe1 : (a -> b) -> (Maybe a -> Maybe b)
passMaybe1 fn x =
  case x of
    Nothing ->
      Nothing
    Just xx ->
      Just (fn xx)


passMaybe2 : (a -> b -> a) -> (Maybe a -> Maybe b -> Maybe a)
passMaybe2 fn x y =
  case x of
    Nothing ->
      Nothing
    Just xx ->
      case y of
        Nothing ->
          Nothing
        Just yy ->
          Just (fn xx yy)
