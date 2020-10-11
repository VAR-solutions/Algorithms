package main
 
import (
    "fmt"
    "math/rand"
)
 
func main() {
 
    fmt.Println("\nComb Sort:")
    slice := generateSlice(15)
    fmt.Println("\nUnsorted:", slice)
    combSort(slice)
    fmt.Println("\nSorted:", slice, "\n")
}
 
// Generates a slice of size with random numbers
func generateSlice(size int) []int {
 
    slice := make([]int, size, size)
    for i := 0; i < size; i++ {
        slice[i] = rand.Intn(999) - rand.Intn(999)
    }
    return slice
}

// Comb Sort
func combSort(items []int) {
    var (
        n = len(items)
        gap = len(items)
        shrink = 1.3
        swapped = true
    )
     
    for swapped {
        swapped = false
            gap = int(float64(gap) / shrink)
            if gap < 1 {
            gap = 1
        }
        for i := 0; i+gap < n; i++ {
            if items[i] > items[i+gap] {
                items[i+gap], items[i] = items[i], items[i+gap]
                swapped = true
            }   
        }
    }
}
