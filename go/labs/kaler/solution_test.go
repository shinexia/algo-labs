package kaler

import "testing"

func TestSolution(t *testing.T) {
	cases := []struct {
		n      int
		expect int
	}{
		{1, 1},
		{2, 3},
		{3, 10},
		{4, 35},
		{5, 126},
	}
	for _, c := range cases {
		out := solution(c.n)
		if out != c.expect {
			t.Errorf("n: %v, out: %v, expect: %v\n", c.n, out, c.expect)
		}
	}
}
