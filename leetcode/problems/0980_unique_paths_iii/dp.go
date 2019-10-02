package _980_unique_paths_iii

func uniquePathsIIIDP(grid [][]int) int {
	R := len(grid)
	C := len(grid[0])
	var target, sr, sc, tr, tc int
	for r := 0; r < R; r++ {
		for c := 0; c < C; c++ {
			node := grid[r][c]
			if node%2 == 0 {
				target |= code(r, c, C)
			}
			if node == 1 {
				sr = r
				sc = c
			} else if node == 2 {
				tr = r
				tc = c
			}
		}
	}
	targetMax := 1 << uint(R*C)
	memo := make([][][]int, R)
	for i := 0; i < R; i++ {
		second := make([][]int, C)
		for j := 0; j < C; j++ {
			third := make([]int, targetMax)
			second[j] = third
		}
		memo[i] = second
	}
	return dp(memo, R, C, sr, sc, tr, tc, target)
}

func code(r, c, C int) int {
	return 1 << uint(r*C+c)
}

func dp(memo [][][]int, R, C, r, c, tr, tc, todo int) int {
	if memo[r][c][todo] != 0 {
		return memo[r][c][todo]
	}
	if r == tr && c == tc {
		if todo == 0 {
			return 1
		}
		return 0
	}
	ans := 0
	for _, dr := range directions {
		nr := r + dr[0]
		nc := c + dr[1]
		if 0 <= nr && nr < R && 0 <= nc && nc < C {
			if (todo & code(nr, nc, C)) != 0 {
				ans += dp(memo, R, C, nr, nc, tr, tc, todo^code(nr, nc, C))
			}
		}
	}
	memo[r][c][todo] = ans
	return ans
}
