// Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.

// Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:

// It must be greater than the original word
// It must be the smallest word that meets the first condition

// If it is not possible, return no answer.

// Input Format
// The first line of input contains T, the number of test cases.
// Each of the next T lines contains w.

// Constraints
// 1 <= T <= 100000
// 1 <= |w| <= 100
// w will contain only letters in the range ascii[a..z].

// Output Format
// For each test case, output the string meeting the criteria. If no answer exists, print no answer.
package main

import (
	"fmt"
	"sort"
)

type sortbytes []byte

func (s sortbytes) Len() int {
	return len(s)
}

func (s sortbytes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortbytes) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func bigger(s string) string {
	b := []byte(s)
	for i := len(b) - 2; i >= 0; i-- {
		v := byte(0xff)
		c := i
		for j := len(b) - 1; j > i; j-- {
			if b[j] > b[i] && b[j]-b[i] < v {
				v = b[j] - b[i]
				c = j
			}
		}
		if c != i {
			b[c], b[i] = b[i], b[c]
			sort.Sort(sortbytes(b[i+1:]))
			return string(b)
		}
	}
	return "no answer"
}

func main() {
	var t int
	var w string
	fmt.Scanf("%d", &t)
	for i := 0; i < t; i++ {
		fmt.Scanf("%s", &w)
		fmt.Println(bigger(w))
	}
}
