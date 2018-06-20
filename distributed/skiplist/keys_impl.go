package skiplist

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
