package _005_longest_palindromic_substring

import "testing"

func TestIsPalindrome(t *testing.T) {
	var cases = []struct {
		s      string
		expect bool
	}{
		{s: "", expect: true},
		{s: "a", expect: true},
		{s: "aa", expect: true},
		{s: "ab", expect: false},
		{s: "aba", expect: true},
		{s: "abc", expect: false},
		{s: "abcdedcba", expect: true},
		{s: "中文文中", expect: true},
	}
	for _, c := range cases {
		if out := isPalindromeS(c.s); out != c.expect {
			t.Errorf("s=%v, out=%v, expect=%v", c.s, out, c.expect)
		}
	}
}

func TestLongestPalindrome(t *testing.T) {
	var cases = []struct {
		s      string
		expect string
	}{
		{s: "", expect: ""},
		{s: "a", expect: "a"},
		{s: "ab", expect: "a"},
		{s: "aa", expect: "aa"},
		{s: "abcdefg", expect: "a"},
		{s: "babad", expect: "bab"},
		{s: "cbbd", expect: "bb"},
		{s: "中文文中", expect: "中文文中"},
	}
	var funcs = []struct {
		name string
		fn   func(s string) string
	}{
		{name: "BruteForce", fn: BruteForce},
		{name: "ExpandAroundCenter", fn: ExpandAroundCenter},
		{name: "ManchersAlgorithm", fn: ManchersAlgorithm},
	}
	for _, f := range funcs {
		for _, c := range cases {
			if out := f.fn(c.s); out != c.expect {
				t.Errorf("fn=%v, s=%v, out=%v, expect=%v", f.name, c.s, out, c.expect)
			}
		}
	}
}
