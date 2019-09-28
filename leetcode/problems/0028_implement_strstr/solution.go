package _028_implement_strstr

// https://leetcode.com/problems/implement-strstr/

func strStr(haystack string, needle string) int {
	n := len(needle)
	switch {
	case n == 0:
		return 0
	case n == len(haystack):
		if haystack == needle {
			return 0
		}
		return -1
	case n > len(haystack):
		return -1
	}
	c0 := needle[0]
	i := 0
	t := len(haystack) - n + 1
	for i < t {
		if haystack[i] != c0 {
			i++
			continue
		}
		if haystack[i:i+n] == needle {
			return i
		}
		i++
	}
	return -1
}
