package _012_integer_to_roman

import "testing"

func TestIntegerToRoman(t *testing.T) {
	cases := []struct {
		in     int
		expect string
	}{
		{3, "III"},
		{4, "IV"},
		{9, "IX"},
		{58, "LVIII"},
		{1994, "MCMXCIV"},
	}
	for _, c := range cases {
		out := intToRoman(c.in)
		if out != c.expect {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
