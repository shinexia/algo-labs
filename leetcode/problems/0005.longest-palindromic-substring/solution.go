package _005_longest_palindromic_substring

// https://leetcode.com/problems/longest-palindromic-substring/description/

func longestPalindrome(s string) string {
	return longestPalindrome1(s)
}

// ------- Brute Force -------
// Time: O(N^3)
// Space: O(1) - not include runes
func longestPalindrome1(s string) string {
	r := []rune(s)
	var (
		N     = len(r)
		start int
		end   int
		maxN  = 0
	)
	for i := 0; i < N; i++ {
		for j := N; j > i; j-- {
			if isPalindrome(r, i, j) && j-i > maxN {
				start = i
				end = j
				maxN = j - i
			}
		}
	}
	return string(r[start:end])
}

// r == nil or r == [] will return true
// eq. r[offset:end]
// Time: O(N)
// Space: O(1)
func isPalindrome(r []rune, offset, end int) bool {
	for i, j := offset, end-1; i < j; i, j = i+1, j-1 {
		if r[i] != r[j] {
			return false
		}
	}
	return true
}

// s == "" will return true
func isPalindromeS(s string) bool {
	r := []rune(s)
	return isPalindrome(r, 0, len(r))
}

// ------- Expand Around Center -------
// Time: O(N^2)
// Space: O(1) - not include runes
func longestPalindrome2(s string) string {
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

// ------- Manacher’s algorithm -------
// Time: O(N)
// Space: O(N)
func longestPalindrome3(s string) string {
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
