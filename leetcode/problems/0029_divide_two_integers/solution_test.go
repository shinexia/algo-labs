package _029_divide_two_integers

import "testing"

func TestDivide(t *testing.T) {
	cases := []struct {
		dividend int
		divisor  int
		expect   int
	}{
		{10, 3, 3},
		{7, -3, -2},
		{-7, 3, -2},
		{-7, -3, 2},
		{0, 1, 0},
		{1, 1, 1},
		{-2147483648, -1, 2147483647},
		{-2147483648, 1, -2147483648},
		{-2147483648, -2147483648, 1},
		{-2147483647, -2147483648, 0},
		{-2147483648, -2147483647, 1},
		{1, -2147483648, 0},
		{-1, -2147483648, 0},
		{2147483647, -2147483648, 0},
		{-2147483647, -2147483648, 0},
		{-2147483648, 2, -1073741824},
		{100, 3, 33},
	}
	for _, c := range cases {
		out := divide(c.dividend, c.divisor)
		if out != c.expect {
			t.Errorf("%v / %v, out: %v, expect: %v", c.dividend, c.divisor, out, c.expect)
		}
	}
}
