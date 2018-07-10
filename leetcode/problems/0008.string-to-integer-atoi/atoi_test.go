package _008_string_to_integer_atoi

import "testing"

func TestMyAtoi(t *testing.T) {
	cases := []struct{
		in string
		expect int
	} {
		{in: "  ", expect: 0},
		{in: " 42  ", expect: 42},
		{in: "   -42  ", expect: -42},
		{in: "   +42  ", expect: 42},
		{in: "   ----42  ", expect: 0},
		{in: "4193 with words", expect: 4193},
		{in: "words and 987", expect: 0},
		{in: "words and --123- suffix  ", expect: 0},
		{in: "-91283472332", expect: -2147483648},
		{in: "91283472332", expect: 2147483647},
		{in: "3.14159", expect: 3},
		{in: "-   234", expect: 0},
	}
	for _, c := range cases {
		if out := myAtoi(c.in); out != c.expect {
			t.Errorf("in=%s, out=%d, expect=%d", c.in, out, c.expect)
		}
	}
}
