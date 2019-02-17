package _003_length_of_longest_substring

import (
	"testing"
	"strings"
)

func TestStringIndex(t *testing.T) {
	s := "hello"

	idx := strings.IndexRune(s, rune('o'))
	if out := s[idx+1:]; out != "" {
		t.Errorf("s=%s, idx+1=%d, out=%s, expect=%s", s, idx+1, out, "")
	}

	if out := strings.IndexRune(s, rune('z')); out != -1 {
		t.Error("not contained rune idx should eq to -1")
	}
}

func TestLongest(t *testing.T) {
	tests := []struct{
		s string
		expect int
	} {
		{s: "", expect: 0},
		{s: "c", expect: 1},
		{s: "bbbbb", expect: 1},
		{s: "abcabcbb", expect: 3},
		{s: "pwwkew", expect: 3},
	}
	for _, test := range tests {
		if out := LengthOfLongestSubstring(test.s); out != test.expect {
			t.Errorf("s=%s, out=%d, expect=%d", test.s, out, test.expect)
		}
	}
}
