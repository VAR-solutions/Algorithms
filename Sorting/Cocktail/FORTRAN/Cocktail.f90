PROGRAM COCKTAIL
  IMPLICIT NONE
 
  INTEGER :: intArray(10) = (/ 4, 9, 3, -2, 0, 7, -5, 1, 6, 8 /)
 
  WRITE(*,"(A,10I5)") "Unsorted array:", intArray
  CALL Cocktail_sort(intArray)
  WRITE(*,"(A,10I5)") "Sorted array  :", intArray
 
CONTAINS
 
  SUBROUTINE Cocktail_sort(a)
    INTEGER, INTENT(IN OUT) :: a(:)
    INTEGER :: i, bottom, top, temp 
    LOGICAL :: swapped
 
    bottom = 1
    top = SIZE(a) - 1
    DO WHILE (bottom < top )
       swapped = .FALSE.
       DO i = bottom, top
          IF (array(i) > array(i+1)) THEN
              temp = array(i)
              array(i) = array(i+1)
              array(i+1) = temp
              swapped = .TRUE.
          END IF
       END DO
       IF (.NOT. swapped) EXIT
       DO i = top, bottom + 1, -1
          IF (array(i) < array(i-1)) THEN
              temp = array(i)
              array(i) = array(i-1)
              array(i-1) = temp
              swapped = .TRUE.
          END IF
       END DO
       IF (.NOT. swapped) EXIT
       bottom = bottom + 1
       top = top - 1
    END DO
  END SUBROUTINE Cocktail_sort
 
END PROGRAM COCKTAIL
