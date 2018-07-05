package _005_longest_palindromic_substring

// Time: O(N)
// Space: O(N)
func ManchersAlgorithm(s string) string {
	r := []rune(s)
	var (
		T = prePocess(r)
		N = len(T)
		P = make([]int, N)
		C = 0
		R = 0
	)
	for i := 1; i < N-1; i++ {
		iMirror := 2*C - i // equals to i' = C - (i - C)
		if R > i {
			P[i] = minInt(R-i, P[iMirror])
		}
		for T[i+1+P[i]] == T[i-1-P[i]] {
			P[i]++
		}
		if t := i + P[i]; t > R {
			C = i
			R = t
		}
	}
	var (
		maxN        = 0
		centerIndex = 0
	)
	for i := 1; i < N-1; i++ {
		if P[i] > maxN {
			maxN = P[i]
			centerIndex = i
		}
	}
	start := (centerIndex - 1 - maxN) / 2
	return string(r[start : start+maxN])
}

func prePocess(r []rune) (T []rune) {
	T = make([]rune, len(r)*2+3)
	T[0] = '^'
	i := 1
	for _, x := range r {
		T[i] = '#'
		i++
		T[i] = x
		i++
	}
	T[i] = '#'
	i++
	T[i] = '$'
	return
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}
