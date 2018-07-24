(module
  (func (export "main") (result i32)
    (local $i i32)
    (local $sum i32)

    (loop
      (if
        (i32.or
          (i32.eq (i32.rem_u (get_local $i) (i32.const 3)) (i32.const 0))
          (i32.eq (i32.rem_u (get_local $i) (i32.const 5)) (i32.const 0))
        )
        (then
          (set_local $sum (i32.add (get_local $sum) (get_local $i)))
        )
      )

      (set_local $i (i32.add (get_local $i) (i32.const 1)))
      (br_if 0 (i32.lt_u (get_local $i) (i32.const 1000)))
    )

    (get_local $sum)
  )
)
