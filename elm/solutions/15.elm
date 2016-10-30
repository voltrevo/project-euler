import Debug
import Dict


sortPair : (comparable, comparable) -> (comparable, comparable)
sortPair (i, j) =
  (min i j, max i j)


isNothing : Maybe a -> Bool
isNothing x =
  case x of
    Nothing ->
      True
    Just _ ->
      False


pathCount
  : Dict.Dict (number, number) number
  -> (number, number)
  -> List (number, number)
  -> number
pathCount cache task tailTasks =
  let
    (i, j) = sortPair task
    lookup (i, j) =
      if i < 0 || j < 0 then
        Just 0
      else if i == 0 && j == 0 then
        Just 1
      else
        Dict.get (sortPair (i, j)) cache
  in case lookup (i, j) of
    Just count ->
      case tailTasks of
        tailHead :: tailTail ->
          pathCount cache tailHead tailTail
        [] ->
          count
    Nothing ->
      case (lookup (i - 1, j), lookup (i, j - 1)) of
        (Just upCount, Just leftCount) ->
          let count = (upCount + leftCount)
          in case tailTasks of
            [] ->
              count
            tailHead :: tailTail ->
              pathCount (Dict.insert (i, j) count cache) tailHead tailTail
        _ ->
          pathCount cache (i - 1, j) ((i, j - 1) :: (i, j) :: tailTasks)


answer : number
answer =
  pathCount Dict.empty (20, 20) []
    |> Debug.log "answer"
