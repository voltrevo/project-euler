module ArrayExtras exposing (last, getFrom, tail)


import Array


last : Array.Array a -> Maybe a
last array =
  Array.get ((Array.length array) - 1) array


getFrom : Int -> Array.Array a -> Array.Array a
getFrom i array =
  Array.slice i (array |> Array.length) array


tail : Array.Array a -> Array.Array a
tail array =
  getFrom 1 array
