package _007_reverse_integer

import "testing"

func TestReverse(t *testing.T)  {
	cases := []struct{
		in int
		expect int
	} {
		{in: 123, expect: 321},
		{in: -123, expect: -321},
		{in: 120, expect: 21},
		{in: 1000000008, expect: 0}, // overflow
	}
	for _, c := range cases {
		if out := reverse(c.in); out != c.expect {
			t.Errorf("in=%d, out=%d, expect=%d", c.in, out, c.expect)
		}
	}
}
