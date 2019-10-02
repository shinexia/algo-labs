package _063_unique_paths_ii

import "testing"

func TestUniquePathsWithObstacles(t *testing.T) {
	cases := []struct {
		obstacleGrid [][]int
		expect       int
	}{
		{[][]int{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2},
	}
	for _, c := range cases {
		out := uniquePathsWithObstacles(c.obstacleGrid)
		if out != c.expect {
			t.Errorf("obstacleGrid: %v, out: %v, expect: %v", c.obstacleGrid, out, c.expect)
		}
	}
}
