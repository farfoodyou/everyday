package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {
	result := make([][]uint8, dy)
	for i := range result {
		b := make([]uint8, dx)
		for y := range b {
			// 给里层slice每个元素赋值
			b[y] = uint8(i^y)
		}
		// 给外层slice每个元素赋值
		result[i] = b
	}
	return result
}

func main() {
	pic.Show(Pic)
}
