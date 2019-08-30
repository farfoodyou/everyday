package main

import "fmt"

// 返回一个“返回int的函数”
func fibonacci() func() int {
	f, s := 0, 1
	return func() int {
		tmp := f + s
		f = s
		s = tmp
		return tmp
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
