package main

import (
	"fmt";
	"math/rand"
	"math"
)

func add(x int, y int) int {
	return x+y
}

func sub(x, y int) int {
	return x-y
}

func swap(x, y string) (string, string) {
	return y, x
}

func split(total int) (x, y int) {
	x = total/4*3
	y = total - x
	return
}

const (
	Big = 1 << 100
	Small = Big >> 97
)

func main() {
	fmt.Println("My favorite number is", rand.Intn(100))
	fmt.Printf("Now you have %g problems.\n", math.Sqrt(7))

	fmt.Println(add(6, 9))
	fmt.Println(sub(4,7))

	a, b := swap("world ", "Hello")
	fmt.Println(a, b)

	x, y := split(100)
	fmt.Println(x, y)

	var i , j = 100, 34
	var str string;
	var k bool = true;
	s , t := "hi there ", 56
	fmt.Println(i, j, str, k, s, t)
	fmt.Println(float64(Big))
	fmt.Println(Small)
}
