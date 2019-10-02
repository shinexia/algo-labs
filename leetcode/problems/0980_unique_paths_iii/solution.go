package _980_unique_paths_iii

// https://leetcode.com/problems/unique-paths-iii/

var directions = [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}

func uniquePathsIII(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	board := make([][]int, m)
	r, c := 0, 0
	todo := 1
	for i := 0; i < m; i++ {
		buf := make([]int, n)
		copy(buf, grid[i])
		board[i] = buf
		for j, x := range buf {
			if x == 1 {
				r, c = i, j
			} else if x == 0 {
				todo++
			}
		}
	}
	return backtrc(board, m, n, r, c, todo, 0)
}

func backtrc(board [][]int, m, n, r, c, todo int, acc int) int {
	if r < 0 || r >= m || c < 0 || c >= n {
		return acc
	}
	curr := board[r][c]
	if curr == -1 {
		return acc
	}
	if curr == 2 {
		if todo == 0 {
			return acc + 1
		}
		return acc
	}
	todo--
	board[r][c] = -1
	for _, direc := range directions {
		acc = backtrc(board, m, n, r+direc[0], c+direc[1], todo, acc)
	}
	board[r][c] = curr
	return acc
}
