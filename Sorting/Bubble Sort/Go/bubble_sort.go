package main
 
import (
  "sort"
  "fmt"
)
 
func main() {
    list := []int{31, 41, 59, 26, 53, 58, 97, 93, 23, 84}
    fmt.Println("unsorted:", list)
 
    bubblesort(sort.IntSlice(list))
    fmt.Println("sorted!  ", list)
}
 
func bubblesort(a sort.Interface) {
    for itemCount := a.Len() - 1; ; itemCount-- {
        hasChanged := false
        for index := 0; index < itemCount; index++ {
            if a.Less(index+1, index) {
                a.Swap(index, index+1)
                hasChanged = true
            }
        }
        if !hasChanged {
            break
        }
    }
}
