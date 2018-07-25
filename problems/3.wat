(module
  (func (export "main") (result i64)
    (local $n i64)
    (local $p i64)
    (local $fMax i64)

    (set_local $n (i64.const 600851475143))
    (set_local $p (i64.const 2))

    (loop
      (if (i64.gt_u (i64.mul (get_local $p) (get_local $p)) (get_local $n))
        (return
          (call $i64_max_u (get_local $n) (get_local $fMax))
        )
      )

      (loop
        (if (i64.eq (i64.rem_u (get_local $n) (get_local $p)) (i64.const 0))
          (then
            (set_local $n (i64.div_u (get_local $n) (get_local $p)))
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
  (func $nextPrime (param $p i64) (result i64)
    (loop
      (set_local $p (i64.add (get_local $p) (i64.const 1)))

      (if (call $isPrime (get_local $p))
        (return (get_local $p))
      )

      (br 0)
    )

    unreachable
  )
  (func $isPrime (param $p i64) (result i32)
    (local $i i64)
    (set_local $i (i64.const 2))

    (loop
      (if (i64.gt_u (i64.mul (get_local $i) (get_local $i)) (get_local $p))
        (return (i32.const 1))
      )

      (if (i64.eq (i64.rem_u (get_local $p) (get_local $i)) (i64.const 0))
        (return (i32.const 0))
      )

      (set_local $i (i64.add (get_local $i) (i64.const 1)))

      (br 0)
    )

    unreachable
  )
  (func $i64_max_u (param $a i64) (param $b i64) (result i64)
    (if (result i64) (i64.gt_u (get_local $a) (get_local $b))
      (then
        (get_local $a)
      )
      (else
        (get_local $b)
      )
    )
  )
)
