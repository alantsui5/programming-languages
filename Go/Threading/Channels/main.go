package main

import (
	"fmt"
	"math/rand"
	"time"
)

func run(name string, win chan bool) {
	i := 0
	for {
		time.Sleep(time.Second)

		if rand.Intn(2) == 1 {
			i++
			fmt.Println("Cheetah", name, "runned", i, "miles!")
			if i == 5 {
				win <- true
				fmt.Println("Cheetah", name, "winned the race")
				break
			}
		} else {
			continue
		}
	}
}

func main() {
	//run("Dan")

	var win = make(chan bool, 10)
	go run("Tom", win)
	go run("Dusty", win)
	go run("Champy", win)
	//Anonymous function

	go run("Bernie", win)
	select {
	case msg := <-win:
		fmt.Println("The game ended", msg)
		//fmt.Scanln()
		//fmt.Println("done")
		return
	}

}
