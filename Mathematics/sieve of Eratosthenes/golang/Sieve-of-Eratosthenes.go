package main

import "fmt"

var MAXN int = 1000

func Sieve() {
  prime := make([]bool, MAXN)
  for i, _ := range prime {
    prime[i] = true
  }
  for i := 2; i < MAXN; i += 1{
    for j := i; i*j < MAXN; j += 1 {
      prime[i*j] = false;
    }
  }
  for i, flag := range prime {
    if (flag == true && i > 1) {
      fmt.Println(i)
    }
  }
}

//execution starts here

func main(){
  fmt.Println("This program prints all the prime numbers from 2 to MAXN")
  Sieve()
}
