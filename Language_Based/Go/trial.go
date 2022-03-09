package main

import (
	"fmt"
	"math"
)

func Sqrt(x float64) float64 {
	z := 0.1
	for math.Abs(z*z - x) > 0.0000001 {
		z -= (z*z -x) / (2*z)
		// fmt.Println(z)
	}
	return z
}

func main() {
	x := 2.0
	fmt.Println(math.Sqrt(x))
	fmt.Println(Sqrt(x))
}
