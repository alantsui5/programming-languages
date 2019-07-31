package main

import (
	"fmt"
	"predator/Lion"
)

type predator interface {
	ChasePrey() string
	EatPrey() string
}

func action(P predator) {
	fmt.Println(P.ChasePrey())
	fmt.Println(P.EatPrey())
}
func main() {
	fmt.Println("hello World")
	pred1, _ := Lion.NewPredator("Anger")
	action(pred1)
}
