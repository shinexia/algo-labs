package lib

import (
	"testing"
)

func TestLoadArrays(t *testing.T) {
	cases := []struct {
		path   string
		N      int
		expect [][]int
	}{
		{
			path:   "testdata/array.txt",
			N:      6,
			expect: [][]int{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}},
		},
	}
	for _, c := range cases {
		N, arr, err := LoadNArrays(c.path)
		if err != nil {
			t.Errorf("err: %v", err)
		}
		if N != c.N {
			t.Errorf("invalid N: %d", N)
		}
		if !ArraysEqualsInt(arr, c.expect) {
			t.Errorf("path: %s, out: %v, expect: %v", c.path, arr, c.expect)
		}
	}

}
