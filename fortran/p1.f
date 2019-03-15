      program p1
      
      integer i, total
      
      total = 0
      
      do i = 1, 999
          if (mod(i, 3) .eq. 0 .or. mod(i, 5) .eq. 0) then
              total = total + i
          endif
      end do
      
      print *, 'total = ', total
      
      end
