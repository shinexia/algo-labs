package kmp

import (
	"testing"
)

var cases = []struct {
	s      string
	p      string
	expect int
}{
	{s: "BBC ABCDAB ABCDABCDABDE", p: "ABCDABD", expect: 15},
	{s: "xpyyubzabcabcabcabcabcabcabcabcabcabcxyzabukxpyksl", p: "abcabcabcabcabcabc", expect: 7},
}

type matcher func(s, p string) int

func testMatch(fn matcher, t *testing.T) {
	for _, c := range cases {
		if out := fn(c.s, c.p); out != c.expect || c.s[out:out+len(c.p)] != c.p {
			t.Errorf("s=%s, p=%s, out=%v, expect=%v, split=%v\n", c.s, c.p, out, c.expect, c.s[out:out+len(c.p)])
		}
	}
}

func benchmarkMatch(fn matcher, b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, c := range cases {
			fn(c.s, c.p)
		}
	}
}
