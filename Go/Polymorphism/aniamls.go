package main

import "fmt"

type animal struct {
	pig
	dog
}

type pig struct {
}

type dog struct {
}

func (a *animal) animalSound() {
	fmt.Println("The animal makes a sound")
}

func (p *pig) animalSound() {
	fmt.Println("The pig says: wee wee")
}

func (d *dog) animalSound() {
	fmt.Println("The dog says: bow wow")
}

func main() {
	myAnimal := new(animal)
	myPig := new(pig)
	myDog := new(dog)

	myAnimal.animalSound()     //animalsound
	myPig.animalSound()        // pigsound
	myDog.animalSound()        // dog Sound
	myAnimal.pig.animalSound() // pigsound
	myAnimal.dog.animalSound() // dogsound
}
