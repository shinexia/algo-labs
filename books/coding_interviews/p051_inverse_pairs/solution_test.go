package p051_inverse_pairs

import "testing"

func TestReversedPairs(t *testing.T) {
	cases := []struct {
		in     []int
		expect int
	}{
		{[]int{}, 0},
		{[]int{1}, 0},
		{[]int{1, 2}, 0},
		{[]int{2, 1}, 1},
		{[]int{7, 5, 6, 4}, 5},
	}
	for _, c := range cases {
		out := InversePairs(c.in)
		if out != c.expect {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
