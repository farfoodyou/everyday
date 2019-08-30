package main

import (
	"fmt"
	"math"
)
const eps = 0.000000001 
func IsSame(x float64, y float64) bool {
	return x - y < eps && y - x > -eps
}

func Sqrt(x float64) float64 {
	z := 1.0
	for z -= (z*z - x) / (2*z); !IsSame(z*z, x); z -= (z*z - x) / (2*z) {
		
	}
	return z
}

func main() {
	fmt.Println(Sqrt(2.0))
	fmt.Println(math.Sqrt(2.0))
}
