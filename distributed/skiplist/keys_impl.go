package skiplist

import "strings"

type Int int

func NewInt(i int) (a Int) {
	a = Int(i)
	return
}

func (i Int) Compare(j interface{}) int {
	switch j.(type) {
	case Int:
		return int(i) - int(j.(Int))
	default:
		panic("invalid j type")
	}
}

type Str string

func NewStr(s string) (a Str) {
	a = Str(s)
	return
}

func (i Str) Compare(j interface{}) int {
	switch j.(type) {
	case Str:
		return strings.Compare(string(i), string(j.(Str)))
	default:
		panic("invalid j type")
	}
}
