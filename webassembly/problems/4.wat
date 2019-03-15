(module
  (func (export "main") (result i32)
    (local $palMax i32)
    (local $i i32)
    (local $j i32)
    (local $ij i32)

    (set_local $i (i32.const 100))

    (loop
      (set_local $j (get_local $i))

      (loop
        (set_local $ij (i32.mul (get_local $i) (get_local $j)))

        (if (call $isPalindrome (get_local $ij))
          (if (i32.gt_u (get_local $ij) (get_local $palMax))
            (set_local $palMax (get_local $ij))
          )
        )

        (set_local $j (i32.add (get_local $j) (i32.const 1)))
        (br_if 0 (i32.le_u (get_local $j) (i32.const 999)))
      )

      (set_local $i (i32.add (get_local $i) (i32.const 1)))
      (br_if 0 (i32.le_u (get_local $i) (i32.const 999)))
    )

    (get_local $palMax)
  )
  (func $isPalindrome (param $n i32) (result i32)
    (local $lPow10 i32)
    (local $rPow10 i32)

    (set_local $rPow10 (i32.const 1))

    (set_local $lPow10 (i32.const 1))

    ;; Find lPow10 = 10^u such that the 1 lines up with the first digit of n
    (loop
      (set_local $lPow10 (i32.mul (get_local $lPow10) (i32.const 10)))
      (br_if 0 (i32.div_u (get_local $n) (get_local $lPow10)))
    )

    ;; Loop above went one power too far, so divide by 10
    (set_local $lPow10 (i32.div_u (get_local $lPow10) (i32.const 10)))

    (loop
      ;; If digits unequal, return false
      (if
        (i32.ne
          (i32.rem_u
            (i32.div_u (get_local $n) (get_local $lPow10))
            (i32.const 10)
          )
          (i32.rem_u
            (i32.div_u (get_local $n) (get_local $rPow10))
            (i32.const 10)
          )
        )
        (return (i32.const 0))
      )

      ;; Move lPow10 one place to the right
      (set_local $lPow10 (i32.div_u (get_local $lPow10) (i32.const 10)))

      ;; Move rPow10 one place to the left
      (set_local $rPow10 (i32.mul (get_local $rPow10) (i32.const 10)))

      (br_if 0 (i32.gt_u (get_local $lPow10) (get_local $rPow10)))
    )

    (i32.const 1)
  )
)
