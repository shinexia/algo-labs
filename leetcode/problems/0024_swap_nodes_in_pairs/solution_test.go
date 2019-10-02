package _024_swap_nodes_in_pairs

import (
	"reflect"
	"testing"
)

func TestSwapNodesInPairs(t *testing.T) {
	cases := []struct {
		in     []int
		expect []int
	}{
		{[]int{1, 2, 3, 4}, []int{2, 1, 4, 3}},
	}
	for _, c := range cases {
		out := swapPairs(makeList(c.in))
		if !reflect.DeepEqual(arrayFromList(out), c.expect) {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}

func makeList(a []int) *ListNode {
	if len(a) == 0 {
		return nil
	}
	head := &ListNode{
		Val: a[0],
	}
	prev := head
	for _, x := range a[1:] {
		l := &ListNode{
			Val: x,
		}
		prev.Next = l
		prev = l
	}
	return head
}

func arrayFromList(a *ListNode) (out []int) {
	for a != nil {
		out = append(out, a.Val)
		a = a.Next
	}
	return
}
