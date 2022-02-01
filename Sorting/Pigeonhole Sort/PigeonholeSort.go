package main

import (
        "fmt"
)

func PigeonholeSort(slice []int) []int {
        min := slice[0]
        max := slice[0]
        for _, e := range slice {
                if e > max {
                        max = e
                }
                if e < min {
                        min = e
                }
        }

        r:= max - min + 1
        phole := make([]int, r)
        for i,_ := range phole {
                phole[i] = 0
        }

        for i, _ := range slice {
                phole[slice[i] - min]++
        }

        index := 0

        for i := 0; i < r; i++ {
                for phole[i] > 0 {
                        phole[i] -= 1
                        slice[index] = i + min
                        index += 1
                }
        }

        return slice
}

func main() {
        slice := []int{43, 41, 82, 2, 16, 7}
        fmt.Println(slice)
        fmt.Println(PigeonholeSort(slice))
}
