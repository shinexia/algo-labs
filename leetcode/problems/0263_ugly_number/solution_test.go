package _263_ugly_number

import "testing"

func TestIsUglyNumber(t *testing.T) {
	cases := []struct {
		number int
		expect bool
	}{
		{-1, false},
		{0, false},
		{1, true},
		{2, true},
		{6, true},
		{8, true},
		{14, false},
	}
	for _, c := range cases {
		out := isUgly(c.number)
		if out != c.expect {
			t.Errorf("number: %v, out: %v, expect: %v", c.number, out, c.expect)
		}
	}
}
