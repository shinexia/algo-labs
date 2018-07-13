package kmp

import "testing"

func TestSimpleMatch(t *testing.T) {
	testMatch(simpleMatch, t)
}


func BenchmarkSimpleMatch(b *testing.B) {
	benchmarkMatch(simpleMatch, b)
}
