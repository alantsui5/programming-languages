package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

type pizza struct {
	Name   string
	Price  float32
	Number int
	Cost   float32
}

func newPizza(name string, price float32) (*pizza, error) {
	if name == "" {
		return nil, errors.New("missing name")
	}

	return &pizza{
		Name:   name,
		Price:  price,
		Number: 0,
		Cost:   0,
	}, nil
}

func (p *pizza) getCost() float32 {
	p.Cost = float32(p.Number) * p.Price
	return p.Cost
}

func main() {
	Pizzas := make(map[string]*pizza)
	var err error
	Pizzas["A"], err = newPizza("pizza A", 123.11)
	check(err)
	Pizzas["B"], err = newPizza("pizza B", 185.11)
	check(err)
	Pizzas["C"], err = newPizza("pizza C", 34.11)
	check(err)

	var totalCost float32

	for {
		fmt.Print("\nBasket --------\n\n")

		if Pizzas["A"].Number > 0 {
			fmt.Printf("%s  %.2f\n", Pizzas["A"].Name, Pizzas["A"].getCost())
		}
		if Pizzas["B"].Number > 0 {
			fmt.Printf("%s  %.2f\n", Pizzas["B"].Name, Pizzas["B"].getCost())
		}
		if Pizzas["C"].Number > 0 {
			fmt.Printf("%s  %.2f\n", Pizzas["C"].Name, Pizzas["C"].getCost())
		}
		fmt.Printf("Total Cost %.2f\n---------------\n\n", totalCost)

		fmt.Println("Please select a pizza to add to your basket:")
		fmt.Printf("1: %s price: %.2f\n", Pizzas["A"].Name, Pizzas["A"].Price)
		fmt.Printf("2: %s price: %.2f\n", Pizzas["B"].Name, Pizzas["B"].Price)
		fmt.Printf("3: %s price: %.2f\n\n", Pizzas["C"].Name, Pizzas["C"].Price)

		fmt.Println("Enter your choice here >> ")
		choices, err := bufio.NewReader(os.Stdin).ReadString('\n')
		choices = strings.TrimSpace(choices)
		check(err)
		choice, err := strconv.Atoi(choices)
		check(err)

		switch choice {
		case 1:
			totalCost += Pizzas["A"].Price
			Pizzas["A"].Number++
			break
		case 2:
			totalCost += Pizzas["B"].Price
			Pizzas["B"].Number++
			break
		case 3:
			totalCost += Pizzas["C"].Price
			Pizzas["C"].Number++
			break
		case 0:
			fmt.Print("Terminating\n\n")
			os.Exit(0)
			break
		default:
			print("You inserted incorrect number")
		}
	}
}
