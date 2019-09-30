package main

import (
	"fmt"
	"strings"
)

func main() {
	sentence := "Hello World"

	fmt.Println(sentence)
	fmt.Println(reverseSentence(sentence))
	fmt.Println(reverseString(sentence))
}

func reverseSentence(str string) string {
	words := strings.Split(str, " ")
	for i := len(words)/2 - 1; i >= 0; i-- {
		opposite := len(words) - i - 1
		words[i], words[opposite] = words[opposite], words[i]
	}
	return strings.Join(words, " ")
}

func reverseString(str string) string {
	runes := []rune(str)
	for i := len(runes)/2 - 1; i >= 0; i-- {
		opposite := len(runes) - i - 1
		runes[i], runes[opposite] = runes[opposite], runes[i]
	}
	return string(runes)
}
