package _264_nth_ugly_number

// https://leetcode.com/problems/ugly-number-ii/

func nthUglyNumber(n int) int {
	if n < 1 {
		return 0
	}
	var (
		index = 1
		dp    = make([]int, n)
		i2    = 0
		i3    = 0
		i5    = 0
	)
	dp[0] = 1
	for ; index < n; index++ {
		var (
			n2 = dp[i2] * 2
			n3 = dp[i3] * 3
			n5 = dp[i5] * 5
		)
		var next = min(n2, n3, n5)
		if next == n2 {
			i2++
		}
		if next == n3 {
			i3++
		}
		if next == n5 {
			i5++
		}
		dp[index] = next
	}
	return dp[index-1]
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	} else {
		if b < c {
			return b
		}
		return c
	}
}
