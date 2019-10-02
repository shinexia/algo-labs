package _980_unique_paths_iii

import "testing"

func TestUniquePathsIII(t *testing.T) {
	cases := []struct {
		obstacleGrid [][]int
		expect       int
	}{
		{[][]int{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}}, 2},
		{[][]int{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}}, 4},
		{[][]int{{0, 1}, {2, 0}}, 0},
	}
	for _, c := range cases {
		out := uniquePathsIIIDP(c.obstacleGrid)
		if out != c.expect {
			t.Errorf("obstacleGrid: %v, out: %v, expect: %v", c.obstacleGrid, out, c.expect)
		}
	}
}
