package _021_merge_two_sorted_lists

import (
	"reflect"
	"testing"
)

func TestMergeTwoLists(t *testing.T) {
	cases := []struct {
		l1     []int
		l2     []int
		expect []int
	}{
		{l1: []int{1, 2, 4}, l2: []int{}, expect: []int{1, 2, 4}},
		{l1: []int{}, l2: []int{1, 3, 4}, expect: []int{1, 3, 4}},
		{l1: []int{1, 2, 4}, l2: []int{1, 3, 4}, expect: []int{1, 1, 2, 3, 4, 4}},
	}
	for _, c := range cases {
		out := arrayFromList(mergeTwoLists(makeList(c.l1), makeList(c.l2)))
		if !reflect.DeepEqual(out, c.expect) {
			t.Errorf("l1: %v, l2: %v, out: %v, expect: %v", c.l1, c.l2, out, c.expect)
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
