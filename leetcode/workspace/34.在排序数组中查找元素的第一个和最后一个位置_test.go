package workspace

import "testing"

func TestSearchRange(t *testing.T) {
	cases := []struct {
		a      []int
		target int
		expect []int
	}{
		{[]int{5, 7, 7, 8, 8, 10}, 8, []int{3, 4}},
		{[]int{5, 7, 7, 8, 8, 10}, 6, []int{-1, -1}},
	}
	for _, c := range cases {
		out := searchRange(c.a, c.target)
		if !arrayEquals(out, c.expect) {
			t.Errorf("nums: %v, target: %v, out: %v, expect: %v\n", c.a, c.target, out, c.expect)
		}
	}
}
