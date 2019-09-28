package _020_valid_parentheses

import "testing"

func TestIsValid(t *testing.T) {
	cases := []struct {
		in     string
		expect bool
	}{
		{in: "[", expect: false},
		{in: "]", expect: false},
		{in: "()", expect: true},
		{in: "()[]{}", expect: true},
		{in: "(]", expect: false},
		{in: "([)]", expect: false},
		{in: "{[]}", expect: true},
	}
	for _, c := range cases {
		out := isValid(c.in)
		if out != c.expect {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
