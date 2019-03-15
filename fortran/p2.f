      program p2
      implicit none
      
      integer fib, fib_last, temp, total
      fib = 1
      fib_last = 1
      total = 0
      
      do while (fib .lt. 4000000)
            temp = fib
            fib = fib + fib_last
            fib_last = temp
            
            if (mod(fib, 2) .eq. 0) then
                total = total + fib
            endif
      enddo
      
      print *, total
      
      end
