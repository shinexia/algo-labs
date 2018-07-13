package kmp

import (
	"testing"
	"reflect"
)

func TestKmpPartialMatchTable(t *testing.T) {
	cases := []struct{
		p string
		expect []int
	} {
		{p: "ABCDABD", expect: []int{-1, 0, 0, 0, 0, 1, 2}},
	}
	for _, c := range cases {
		if out := kmpPartialMatchTable([]byte(c.p)); !reflect.DeepEqual(out, c.expect) || len(out) != len(c.p) {
			t.Errorf("p=%v, out=%v, expect=%v\n", c.p, out, c.expect)
		}
	}
}

func TestKmpMatch(t *testing.T) {
	testMatch(kmpMatch, t)
}

func BenchmarkKmpMatch(b *testing.B) {
	benchmarkMatch(kmpMatch, b)
}
