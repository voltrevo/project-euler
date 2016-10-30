module MaybeExtras exposing (unmaybe)


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
