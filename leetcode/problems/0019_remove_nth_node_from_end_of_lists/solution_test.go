package _019_remove_nth_node_from_end_of_lists

import (
	"reflect"
	"testing"
)

func TestRemoveNthFromEnd(t *testing.T) {
	cases := []struct {
		in     []int
		nth    int
		expect []int
	}{
		{[]int{1, 2, 3, 4, 5}, 2, []int{1, 2, 3, 5}},
	}
	for _, c := range cases {
		out := removeNthFromEnd(makeList(c.in), c.nth)
		if !reflect.DeepEqual(arrayFromList(out), c.expect) {
			t.Errorf("in: %v, nth: %v, out: %v, expect: %v", c.in, c.nth, out, c.expect)
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
