package main

import "testing"

func TestNewPizza(t *testing.T) {
	p, err := newPizza("", 100)
	if err != nil {
		t.Fatal("got errors:", err)
	}

	if p == nil {
		t.Error("pizza should be nil")
	}
}
