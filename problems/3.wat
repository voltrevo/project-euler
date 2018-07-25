(module
  (func (export "main") (result i32)
    (local $n i32)
    (local $p i32)
    (local $fMax i32)

    (set_local $n (i32.const 13195))
    (set_local $p (i32.const 2))

    (loop
      (if (i32.gt_u (i32.mul (get_local $p) (get_local $p)) (get_local $n))
        (return
          (call $i32_max_u (get_local $n) (get_local $fMax))
        )
      )

      (loop
        (if (i32.eq (i32.rem_u (get_local $n) (get_local $p)) (i32.const 0))
          (then
            (set_local $n (i32.div_u (get_local $n) (get_local $p)))
            (set_local $fMax (get_local $p))
            (br 1)
          )
        )
      )

      (set_local $p (call $nextPrime (get_local $p)))
      (br 0)
    )

    unreachable
  )
  (func $nextPrime (param $p i32) (result i32)
    (loop
      (set_local $p (i32.add (get_local $p) (i32.const 1)))

      (if (call $isPrime (get_local $p))
        (return (get_local $p))
      )

      (br 0)
    )

    unreachable
  )
  (func $isPrime (param $p i32) (result i32)
    (local $i i32)
    (set_local $i (i32.const 2))

    (loop
      (if (i32.gt_u (i32.mul (get_local $i) (get_local $i)) (get_local $p))
        (return (i32.const 1))
      )

      (if (i32.eq (i32.rem_u (get_local $p) (get_local $i)) (i32.const 0))
        (return (i32.const 0))
      )

      (set_local $i (i32.add (get_local $i) (i32.const 1)))

      (br 0)
    )

    unreachable
  )
  (func $i32_max_u (param $a i32) (param $b i32) (result i32)
    (if (result i32) (i32.gt_u (get_local $a) (get_local $b))
      (then
        (get_local $a)
      )
      (else
        (get_local $b)
      )
    )
  )
)
