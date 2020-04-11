package workspace

/*
 * @lc app=leetcode.cn id=36 lang=golang
 *
 * [36] 有效的数独
 */

// @lc code=start
func isValidSudoku(board [][]byte) bool {
	return isValidSudokuRow(board) && isValidSudokuCol(board) && isValidSudokuWin(board)
}

func isValidSudokuRow(board [][]byte) bool {
	for _, row := range board {
		var a [9]int
		for _, x := range row {
			if x == '.' {
				continue
			}
			idx := x - '1'
			if a[idx] == 1 {
				return false
			}
			a[idx] = 1
		}
	}
	return true
}

func isValidSudokuCol(board [][]byte) bool {
	for j := 0; j < 9; j++ {
		var a [9]int
		for i := 0; i < 9; i++ {
			x := board[i][j]
			if x == '.' {
				continue
			}
			idx := x - '1'
			if a[idx] == 1 {
				return false
			}
			a[idx] = 1
		}
	}
	return true
}

func isValidSudokuWin(board [][]byte) bool {
	for m := 0; m < 9; m += 3 {
		for n := 0; n < 9; n += 3 {
			var a [9]int
			for i := 0; i < 3; i++ {
				for j := 0; j < 3; j++ {
					x := board[m+i][n+j]
					if x == '.' {
						continue
					}
					idx := x - '1'
					if a[idx] == 1 {
						return false
					}
					a[idx] = 1
				}
			}
		}
	}
	return true
}

// @lc code=end
