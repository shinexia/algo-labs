package _002_add_two_numbers

import (
	"testing"
)

func TestAddTwoNumbers(t *testing.T) {
	tests := []struct{
		l1 []int
		l2 []int
		expect []int
	} {
		{l1: nil, l2: nil, expect: nil},
		{l1: nil, l2: []int{1}, expect: []int{1}},
		{l1: []int{1}, l2: nil, expect: []int{1}},
		{l1: []int{2, 4, 3}, l2: []int{5, 6, 4}, expect: []int{7, 0, 8}},
	}
	for _, test := range tests {
		if out := list2array(addTwoNumbers(array2list(test.l1), array2list(test.l2))); !arrayEq(out, test.expect) {
			t.Errorf("l1=%v, l2=%v, out=%v, expect=%v", test.l1, test.l2, out, test.expect)
		}
	}
}

func array2list(l []int) *ListNode {
	var root, prev *ListNode
	for _, a := range l {
		t := &ListNode{
			Val: a,
			Next: nil,
		}
		if prev == nil {
			root = t
			prev = t
		} else {
			prev.Next = t
			prev = t
		}
	}
	return root
}

func list2array(root *ListNode) []int {
	out := make([]int, 0)
	for root != nil {
		out = append(out, root.Val)
		root = root.Next
	}
	return out
}

// not discriminate nil array from empty array (eg. []int{})
func arrayEq(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, t := range a {
		if t != b[i] {
			return false
		}
	}
	return true
}
