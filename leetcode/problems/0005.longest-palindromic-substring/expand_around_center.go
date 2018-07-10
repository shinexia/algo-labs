package _005_longest_palindromic_substring

// Time: O(N^2)
// Space: O(1) - not include runes
func ExpandAroundCenter(s string) string {
	r := []rune(s)
	var (
		N     = len(r)
		start int
		end   int
		maxN  = 0
	)
	for i := 0; i < N; i++ {
		n1 := expandAroundCenter(r, i, i, N)
		n2 := expandAroundCenter(r, i, i+1, N)
		n := maxInt(n1, n2)
		if n > maxN {
			maxN = n
			start = i - (n-1)/2
			end = i + n/2 + 1
		}
	}
	return string(r[start:end])
}

func expandAroundCenter(r []rune, left, right, N int) int {
	var (
		L = left
		R = right
	)
	for L >= 0 && R < N && r[L] == r[R] {
		L--
		R++
	}
	return R - L - 1 // or = (R - 1) - (L + 1) + 1
}

// get the maximum
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
