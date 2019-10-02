package _062_unique_paths

// https://leetcode.com/problems/unique-paths/

func uniquePaths(m int, n int) int {
	board := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		board[i] = make([]int, n+1)
	}
	board[0][1] = 1
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			board[i][j] = board[i-1][j] + board[i][j-1]
		}
	}
	return board[m][n]
}
