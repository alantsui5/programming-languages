package Lion

import (
	"errors"
	"fmt"
)

type Lion struct {
	Name string
}

func (l Lion) ChasePrey() string {
	return fmt.Sprintf("Lion %s is chasing prey.", l.Name)
}

func (l Lion) EatPrey() string {
	return fmt.Sprintf("Lion %s is eating prey.", l.Name)
}

func NewPredator(name string) (*Lion, error) {
	if name == "" {
		return nil, errors.New("missing name")
	}
	return &Lion{
		Name: name,
	}, nil
}
