package main
 
import (
    "fmt"
    "math/rand"
)
 
func main() {
 
    fmt.Println("\nPancake Sort:")
    slice := generateSlice(15)
    fmt.Println("\nUnsorted:", slice)
    pancakeSort(slice)
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

// Pancake Sort
func pancakeSort(items []int) {
for uns := len(items) - 1; uns > 0; uns-- {
        // find largest in unsorted range
        lx, lg := 0, items[0]
        for i := 1; i <= uns; i++ {
            if items[i] > lg {
                lx, lg = i, items[i]
            }
        }
        // move to final position in two flips
        flip(lx, items)
        flip(uns, items)
    }
}

// Flip 
func flip(r int, items []int) {
    for l := 0; l < r; l, r = l+1, r-1 {
        items[l], items[r] = items[r], items[l]
    }
}
