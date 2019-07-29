package main

import (
	"errors"
)

type Pizza struct {
	Name  string
	Price float32
}

func (p *Pizza) _SetName(name string) string {
	if name != "" {
		p.Name = name
	}
	return p.Name
}

func newPizza(name string, price float32) (*Pizza, error) {
	if name == "" {
		return nil, errors.New("missing name")
	}

	return &Pizza{
		Name:  name,
		Price: price,
	}, nil
}

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	Pizzas := make(map[string]*Pizza)
	var err error
	Pizzas["A"], err = newPizza("Pizza A", 123.11)
	check(err)
	Pizzas["B"], err = newPizza("Pizza B", 185.11)
	check(err)
	Pizzas["C"], err = newPizza("Pizza C", 34.11)
	check(err)

}
