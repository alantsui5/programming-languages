package main

import "fmt"

func run(name string) {
	for i := 0; i < 5; i++ {
		fmt.Println("Cheetah", name, "runned", i, "miles!")
	}
}

func main() {
	//run("Dan")

	go run("Tom")
	go run("Dusty")
	go run("Champy")
	//Anonymous function
	go func(name string) {
		fmt.Println("Cat", name, "walks 0.5 miles")
	}("Daisy")

	go run("Bernie")

	fmt.Scanln()
	fmt.Println("done")
}
