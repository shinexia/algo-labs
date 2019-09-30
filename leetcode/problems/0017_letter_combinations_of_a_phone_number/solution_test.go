package _017_letter_combinations_of_a_phone_number

import (
	"reflect"
	"testing"
)

func TestLetterCombinations(t *testing.T) {
	cases := []struct {
		in     string
		expect []string
	}{
		{"", []string{}},
		{"23", []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
	}
	for _, c := range cases {
		out := letterCombinations(c.in)
		if !reflect.DeepEqual(out, c.expect) {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
