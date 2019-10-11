package workspace

import "testing"

func TestIsMatch(t *testing.T) {
	cases := []struct {
		s      string
		p      string
		expect bool
	}{
		{"abcd", "ab*c*d", true},
		{"abce", "ab*c*d", false},
		{"abcde", "ab*c*d", false},
		{"abd", "ab*c*d", true},
		{"ad", "ab*c*d", true},
		{"bcd", "ab*c*d", false},
		{"abcd", "*ab*c*d", false},
		{"aa", "a", false},
		{"", "a*", true},
		{"a", "a*", true},
		{"aaaaa", "a*", true},
		{"ab", ".*", true},
		{"aa", "a*a", true},
		{"a", "a*a", true},
		{"", "a*a", false},
		{"a", "a*aa", false},
		{"aa", "a*aa", true},
		{"mississippi", "mis*is*ip*.", true},
		{"aaa", "ab*a*c*a", true},
		{"ab", "a*ba", false},
	}
	for _, c := range cases {
		out := isMatch(c.s, c.p)
		if out != c.expect {
			t.Errorf("s: %v, p: %v, out: %v, expect: %v", c.s, c.p, out, c.expect)
		}
	}
}
