package main

import "fmt"

func average(nums ...int) float32 {
	total := 0
	length := 0
	for _, height := range nums {
		total += height
		length++
	}
	return float32(total) / float32(length)
}

func main() {
	fmt.Printf("Average: %.2f\n", average(1, 5, 4, 2, 45, 13, 123, 24, 21, 123))

}
