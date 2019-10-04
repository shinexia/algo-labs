package p003_find_duplicate

import "testing"

func TestDuplicate(t *testing.T) {
	cases := []struct {
		in     []int
		expect []int
	}{
		{[]int{2, 3, 1, 0, 2, 5, 3}, []int{2, 3}},
		{[]int{}, []int{-1}},
		{nil, []int{-1}},
		{[]int{0, 1}, []int{-1}},
		{[]int{0, 1, 5}, []int{-1}},
	}
	for _, c := range cases {
		out := duplicate(c.in)
		if !contains(c.expect, out) {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}

func TestDuplicate2(t *testing.T) {
	cases := []struct {
		in     []int
		expect []int
	}{
		{[]int{2, 3, 1, 4, 6, 5, 3}, []int{3}},
		{[]int{}, []int{-1}},
		{nil, []int{-1}},
		{[]int{0, 1}, []int{-1}},
		{[]int{0, 1, 5}, []int{-1}},
	}
	for _, c := range cases {
		out := duplicate2(c.in)
		if !contains(c.expect, out) {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}


func contains(nums []int, a int) bool {
	for _, n := range nums {
		if n == a {
			return true
		}
	}
	return false
}
