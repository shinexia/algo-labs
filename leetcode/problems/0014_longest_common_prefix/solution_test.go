package _014_longest_common_prefix

import "testing"

func TestLongestCommonPrefix(t *testing.T) {
	cases := []struct {
		in     []string
		expect string
	}{
		{in: []string{"a", "a"}, expect: "a"},
		{in: []string{"abcef", "abdc", "abd"}, expect: "ab"},
		{in: []string{"abcef", "abdc", ""}, expect: ""},
		{in: []string{"今天天气", "今天这样", "今天天气怎样"}, expect: "今天"},
	}
	for _, c := range cases {
		out := longestCommonPrefix(c.in)
		if out != c.expect {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
