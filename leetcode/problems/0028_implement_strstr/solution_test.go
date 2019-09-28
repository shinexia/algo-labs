package _028_implement_strstr

import (
	"strings"
	"testing"
)

func TestStrStr(t *testing.T) {
	cases := []struct {
		haystack string
		needle   string
		expect   int
	}{
		{"hello", "ll", 2},
		{"aaaaa", "bba", -1},
		{"hello", "", 0},
		{"", "", 0},
		{"hell", "hello", -1},
		{"mississippi", "issip", 4},
	}
	for _, c := range cases {
		out := strStr(c.haystack, c.needle)
		if out != c.expect || strings.Index(c.haystack, c.needle) != c.expect {
			t.Errorf("haystack: %v, needle: %v, out: %v, expect: %v", c.haystack, c.needle, out, c.expect)
		}
	}
}
