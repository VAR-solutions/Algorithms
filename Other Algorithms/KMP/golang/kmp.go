//Implementation of Knuth Morris Pratt (KMP) algorithm for pattern searching

// Author: Saloni Rajeev Kumar
// Date: Oct 7, 2018

package main
import (
	"fmt"
	"bufio"
	"os"
)

var flag = 0

func calculate_lps(pat string, m int, lps []int){
  len := 0 // length of the previous longest suffix
  lps[0] = 0

  i:=1
  for i<m {
    if pat[i]==pat[len]{
      len++
      lps[i] = len
      i++
    } else {
      if len!=0{
        len = lps[len-1]
      } else {
        lps[i]=0
        i++
      }
    }
  }
}

func kmp_search(pat string, text string){
  n := len(text)-1 // to compensate for \n at the end
  m := len(pat)-1

  lps := make([]int, m)

  calculate_lps(pat, m, lps)

  i := 0
  j := 0

  for i<n {
    if pat[j]==text[i]{
      j++
      i++
    }

    if j==m {
      fmt.Println("Found pattern at address", i-j)
      j = lps[j-1]
      flag++
    } else if i<n && pat[j]!=text[i] {
      if j!=0{
        j=lps[j-1]
      } else {
        i++
      }
    }
  }
  if flag==0 {
    fmt.Println("Not found")
  }
}


func main(){
	reader := bufio.NewReader(os.Stdin)

  // Read text from user
  fmt.Println("Enter text: ")
  text, _ := reader.ReadString('\n')

  // Read pattern to be matched from user
  fmt.Println("Enter pattern: ")
  pat, _ := reader.ReadString('\n')

  kmp_search(pat, text)

}
