package _063_unique_paths_ii

// https://leetcode.com/problems/unique-paths-ii/

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m := len(obstacleGrid)
	n := len(obstacleGrid[0])
	var board = make([][]int, m+1)
	for i := 0; i <= m; i++ {
		buf := make([]int, n+1)
		if i > 0 {
			copy(buf[1:], obstacleGrid[i-1])
		}
		board[i] = buf
	}
	board[0][1] = 1
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if board[i][j] > 0 {
				board[i][j] = 0
			} else {
				board[i][j] = board[i-1][j] + board[i][j-1]
			}
		}
	}
	return board[m][n]
}
