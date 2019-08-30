package main

import (
	"golang.org/x/tour/wc"
	"strings"
	"fmt"
)

func WordCount(s string) map[string]int {
	arr := strings.Split(s, " ")
	res := make(map[string]int)
	for _, v := range arr {
		res[v] ++
	}		
	return res
}

func main() {
	s := strings.Split("abc,abc", ",")
    fmt.Println(s, len(s))
	wc.Test(WordCount)
}
