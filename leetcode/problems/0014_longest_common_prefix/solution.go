package _014_longest_common_prefix

// https://leetcode.com/problems/longest-common-prefix/

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	if len(strs) == 1 {
		return strs[0]
	}
	prefix := strs[0]
	left := strs[1:]
	maxLength := len(prefix)
	for _, s := range left {
		n := len(s)
		if n < maxLength {
			maxLength = n
		}
	}
	prefix = prefix[:maxLength]
	for i, p := range []byte(prefix) {
		for _, s := range left {
			if s[i] != p {
				return prefix[:i]
			}
		}
	}
	return prefix
}
