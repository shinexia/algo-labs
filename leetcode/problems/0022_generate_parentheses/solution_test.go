package _022_generate_parentheses

import (
	"reflect"
	"testing"
)

func TestGenerateParenthesis(t *testing.T) {
	cases := [] struct {
		in     int
		expect []string
	}{
		{3, []string{"((()))", "(()())", "(())()", "()(())", "()()()"}},
	}
	for _, c := range cases {
		out := generateParenthesis(c.in)
		if !reflect.DeepEqual(out, c.expect) {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
