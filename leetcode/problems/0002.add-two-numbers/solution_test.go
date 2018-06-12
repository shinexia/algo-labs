package _002_add_two_numbers

import (
	"testing"
)

func TestAddTwoNumbers(t *testing.T) {
	l1 := &ListNode{
		Val: 2,
		Next: &ListNode{
			Val: 4,
			Next: &ListNode{
				Val: 3,
			},
		},
	}

	l2 := &ListNode{
		Val: 5,
		Next: &ListNode{
			Val: 6,
			Next: &ListNode{
				Val: 4,
			},
		},
	}

	out := addTwoNumbers(l1, l2)
	rights := []int{7, 0, 8}
	for i := 0; out != nil;  out = out.Next {
		if out.Val != rights[i] {
			t.Error()
		}
		i++
	}
}
