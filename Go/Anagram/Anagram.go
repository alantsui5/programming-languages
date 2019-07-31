package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode/utf8"
)

func main() {
	anagram2()
}

// Modulise

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func prompt(text string, path ...string) string {
	if text == "text" {
		fmt.Println("Please input text of string:")
	}
	reader := bufio.NewReader(os.Stdin)
	string1, err := reader.ReadString('\n')
	check(err)
	string1 = strings.TrimSpace(string1)
	return string1
}

func reversed(s string) string {
	o := make([]rune, utf8.RuneCountInString(s))
	i := len(o)
	for _, c := range s {
		i--
		o[i] = c
	}
	return string(o)
}

func anagram1() {
	result := prompt("text")
	fmt.Println(result)
	fmt.Println("(" + reversed(result) + ")")
}

func anagram2() {
	fileName := prompt("text")
	fmt.Println(fileName)
	file, err := os.Open(fileName)
	defer file.Close()
	check(err)
	data := bufio.NewReader(file)
	var line string
	for {
		line, err = data.ReadString('\n')
		line = strings.TrimSpace(line)
		fmt.Println(line)
		fmt.Println("(" + reversed(line) + ")")
		if err != nil {
			break
		}
	}
}
