package _834_sum_of_distances_in_tree

import (
	"os"
	"testing"

	"github.com/shinexia/algorithm-labs/leetcode/lib"
)

type TestCase struct {
	N      int
	edges  [][]int
	expect []int
}

func loadTest(path string) TestCase {
	N, arr, err := lib.LoadNArrays(path)
	if err != nil {
		os.Exit(1)
	}
	return TestCase{
		N:     N,
		edges: arr,
	}
}

func TestNumOfDistancesInTree(t *testing.T) {
	cases := []TestCase{
		{
			N:      6,
			edges:  [][]int{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}},
			expect: []int{8, 12, 6, 10, 10, 10},
		},
		loadTest("test.txt"),
	}
	for _, c := range cases {
		out := sumOfDistancesInTree(c.N, c.edges)
		if !lib.ArrayEqualsInt(out, c.expect) {
			t.Errorf("N: %d, out: %v, expect: %v\n", c.N, out, c.expect)
		}
	}
}
