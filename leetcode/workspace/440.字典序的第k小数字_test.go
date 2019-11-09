package workspace

import "testing"

func TestFindKthNumber(t *testing.T) {
	cases := []struct {
		n      int
		k      int
		expect int
	}{
		{13, 2, 10},
		{234, 3, 100},
		{234, 4, 101},
	}
	for _, c := range cases {
		out := findKthNumber(c.n, c.k)
		if out != c.expect {
			t.Errorf("n: %v, k: %v, out: %v, expect: %v", c.n, c.k, out, c.expect)
		}
	}
}
