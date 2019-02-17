package _005_longest_palindromic_substring

// Time: O(N^3)
// Space: O(1) - not include runes
func BruteForce(s string) string {
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
