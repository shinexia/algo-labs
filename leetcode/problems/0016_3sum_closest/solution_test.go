package _016_3sum_closest

import "testing"

func TestThreeSumClosest(t *testing.T) {
	cases := []struct {
		in     []int
		target int
		expect int
	}{
		{[]int{-1, 2, 1, -4}, 1, 2},
		{[]int{1, 2, 4, 8, 16, 32, 64, 128}, 82, 82},
	}
	for _, c := range cases {
		out := threeSumClosest(c.in, c.target)
		if out != c.expect {
			t.Errorf("in: %v, target: %v, out: %v, expect: %v", c.in, c.target, out, c.expect)
		}
	}
}
