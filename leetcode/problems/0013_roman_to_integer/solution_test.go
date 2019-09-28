package _013_roman_to_integer

import "testing"

func TestRomanToInt(t *testing.T) {
	cases := []struct {
		in     string
		expect int
	}{
		{in: "", expect: 0},
		{in: "I", expect: 1},
		{in: "V", expect: 5},
		{in: "III", expect: 3},
		{in: "IV", expect: 4},
		{in: "IX", expect: 9},
		{in: "LVIII", expect: 58},
	}
	for _, c := range cases {
		out := romanToInt(c.in)
		if out != c.expect {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
