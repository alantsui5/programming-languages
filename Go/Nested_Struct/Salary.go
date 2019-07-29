package main

import "fmt"

type Salary struct {
	Basic, HR_Assistant, TA float64
}

type Employee struct {
	FirstName, LastName, Email string
	Age                        int
	MonthlySalary              []Salary
}

func main() {
	e := &Employee{
		FirstName: "John",
		LastName:  "Doe",
		Email:     "john_doe@123.com",
		Age:       25,
		MonthlySalary: []Salary{
			Salary{
				Basic:        12322,
				HR_Assistant: 2300,
				TA:           1112,
			},
			Salary{
				Basic:        12322,
				HR_Assistant: 2300,
				TA:           1112,
			},
			Salary{
				Basic:        12322,
				HR_Assistant: 2300,
				TA:           1112,
			},
		},
	}
	fmt.Println(e.FirstName, e.LastName)
	fmt.Println(e.Age)
	fmt.Println(e.Email)
	fmt.Println(e.MonthlySalary[0])
	fmt.Println(e.MonthlySalary[1])
	fmt.Println(e.MonthlySalary[2])
}
