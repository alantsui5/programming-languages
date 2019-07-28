package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode/utf8"
)

func main() {
	Anagram2()

}
func Anagram2() {
	var str string = "Hello World"
	fmt.Println("(" + reversed(str) + ")")
}
func Anagram1() {
	fmt.Println("Please input text of string:")
	reader := bufio.NewReader(os.Stdin)

	result, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("read error:", err)
	}
	fmt.Println(result)
	fmt.Println("(" + reversed(result) + ")")
}
func reversed(s string) string {
	s = strings.TrimSpace(s)
	o := make([]rune, utf8.RuneCountInString(s))
	i := len(o)
	for _, c := range s {
		i--
		o[i] = c
	}
	return string(o)
}
