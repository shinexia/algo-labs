package _113_path_sum_ii

import (
	"testing"

	"github.com/shinexia/algorithm-labs/leetcode/lib"
)

func TestPathSum(t *testing.T) {
	cases := []struct {
		nums   []int
		expect [][]int
	}{
		{
			nums:   []int{5, lib.Nil, 8, lib.Nil, 4, 5, 1},
			expect: [][]int{{5, 8, 4, 5}},
		},
	}
	for _, c := range cases {
		root := lib.NewTreeNode(c.nums)
		out := pathSum(root, 22)
		if !lib.ArraysEqualsInt(out, c.expect) {
			t.Errorf("nums: %s, out: %s, expect: %s\n", lib.ArrayToStringInt(c.nums), lib.ArraysToStringInt(out), lib.ArraysToStringInt(c.expect))
		}
	}
}
