package _020_valid_parentheses

// https://leetcode.com/problems/valid-parentheses/
var left = make(map[byte]byte)

func init() {
	left['('] = ')'
	left['['] = ']'
	left['{'] = '}'
}

func isValid(s string) bool {
	stack := make([]byte, 0)
	rStack := make([]byte, 0)
	for _, b := range []byte(s) {
		r, isLeft := left[b]
		if isLeft {
			stack = append(stack, b)
			rStack = append(rStack, r)
		} else {
			length := len(stack) - 1
			if length < 0 || rStack[length] != b {
				return false
			}
			stack = stack[:length]
			rStack = rStack[:length]
		}
	}
	return len(stack) == 0
}
