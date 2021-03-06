import Debug


import Loop exposing (loop)


type alias Fib =
  { last: Int
  , curr: Int
  }


fibStart : Fib
fibStart =
  { last = 0
  , curr = 1
  }


fibNext : Fib -> Fib
fibNext fib =
  { last = .curr fib
  , curr = (.last fib) + (.curr fib)
  }


answer : Int
answer =
  (loop
    { fib = fibStart
    , sum = 0
    }
    (\state ->
      (state |> .fib |> .curr) < 4000000
    )
    (\state ->
      { fib = state |> .fib |> fibNext
      , sum =
        let currFib = state |> .fib |> .curr
        in (.sum state) + if currFib % 2 == 0 then currFib else 0
      }
    )
  )
    |> .sum
    |> Debug.log "answer"
