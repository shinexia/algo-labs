package _011_container_with_most_water

import "testing"

func TestMaxArea(t *testing.T) {
	cases := []struct {
		in     []int
		expect int
	}{
		{[]int{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
	}
	for _, c := range cases {
		out := maxArea(c.in)
		if out != c.expect {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
