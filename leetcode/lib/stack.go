package lib

type StackInt []int

func (s *StackInt) Push(a int) {
	*s = append(*s, a)
}

func (s *StackInt) Pop() (int, bool) {
	ns := len(*s)
	if ns == 0 {
		return 0, false
	}
	r := (*s)[ns-1]
	*s = (*s)[:ns-1]
	return r, true
}
