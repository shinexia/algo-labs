package lib

import "testing"

func TestStack(t *testing.T) {
	var stack StackInt
	stack.Push(1)
	stack.Push(2)
	stack.Push(3)
	a, ok := stack.Pop()
	if a != 3 || !ok {
		t.Errorf("a: %d, ok: %v", a, ok)
	}
	if !ArrayEqualsInt(stack, []int{1, 2}) {
		t.Errorf("stack: %v", stack)
	}
}
