package main

import "fmt"

func main() {
	println("Type ")
}

func prompt() (int, float32) {
	fmt.Println("Type sotck number:")
	var stockNum int
	fmt.Scanf("%d", &stockNum)
	fmt.Println(stockNum)

	price := fetchPrice(stockNum)
	return stockNum, price
}

func fetchPrice(stockNum int) float32 {

}

func buyStock(stockNum int, price float32) {
	addQuery(stockNum, price)
}

func addQuery(stockNum int, price float32) {

}
