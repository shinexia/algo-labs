package _062_unique_paths

import "testing"

func TestUniquePaths(t *testing.T) {
	cases := []struct {
		m      int
		n      int
		expect int
	}{
		{3, 2, 3},
		{7, 3, 28},
		{51, 9, 1916797311},
	}
	for _, c := range cases {
		out := uniquePaths(c.m, c.n)
		if out != c.expect {
			t.Errorf("m: %v, n: %v, out: %v, expect: %v", c.m, c.n, out, c.expect)
		}
	}
}
