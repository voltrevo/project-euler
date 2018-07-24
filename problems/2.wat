(module
  (func (export "main") (result i32)
    (local $sum i32)
    (local $fib1 i32)
    (local $fib2 i32)
    (local $fib3 i32)

    (set_local $fib1 (i32.const 1))
    (set_local $fib2 (i32.const 1))

    (block
      (loop
        (set_local $fib3 (i32.add
          (get_local $fib1)
          (get_local $fib2)
        ))

        (set_local $fib1 (get_local $fib2))
        (set_local $fib2 (get_local $fib3))

        (br_if 1 (i32.gt_u (get_local $fib2) (i32.const 4000000)))

        (if (i32.eq (i32.rem_u (get_local $fib2) (i32.const 2)) (i32.const 0))
          (set_local $sum (i32.add (get_local $sum) (get_local $fib2)))
        )

        (br 0)
      )
    )

    (get_local $sum)
  )
)
