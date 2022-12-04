arr = Array(4, 6, 2, 7, 3, 5, 1, 8, 10, 22, 33, 15, 11, 8)
 
n = UBound(arr)
Do
  Swap = False
  For j = LBound(arr) to n - 1
      If arr(j) > arr(j + 1) Then
         TempValue = arr(j + 1)
         arr(j + 1) = arr(j)
         arr(j) = TempValue
         Swap = True
      End If
  Next
  n = n - 1  ' skip an in-place element each time
Loop Until Not Swap
 
s = ""
For i = LBound(arr) To UBound(arr)
    s = s & arr(i) & ","
Next    
 
WScript.Echo s
