package skiplist

type Int int

func NewInt(i int) (a Int) {
	a = Int(i)
	return
}

func (i Int) Compare(j interface{}) int {
	switch v := j.(type) {
	case Int:
		return int(i) - int(v)
	default:
		panic("invalid j type")
	}
}
