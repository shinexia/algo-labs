package _008_string_to_integer_atoi

import (
	"math"
	"unicode"
)

// https://leetcode.com/problems/string-to-integer-atoi/solution/

func myAtoi(str string) (y int) {
	var nums []rune
	var sign rune
	step := 0
	for _, r := range []rune(str) {
		switch step {
		case 0:
			switch {
			case r == ' ':
				continue
			case r == '-', r == '+':
				sign = r
				step++
			case unicode.IsDigit(r):
				nums = append(nums, r)
				step++
			default:
				step = 101
				nums = nil
				sign = 0
			}
		case 1:
			switch {
			case unicode.IsDigit(r):
				nums = append(nums, r)
			default:
				step = 101
			}
		}
		if step > 100 {
			// finished
			break
		}
	}
	if len(nums) > 0 {
		var fn func(a, b int) int
		if sign == '-' {
			fn = func(a, b int) int {
				return a - b
			}
		} else {
			fn = func(a, b int) int {
				return a + b
			}
		}
		for _, r := range nums {
			y = fn(y*10, rune2int(r))
			if y < math.MinInt32 {
				return math.MinInt32
			} else if y > math.MaxInt32 {
				return math.MaxInt32
			}
		}
	}
	return
}

func rune2int(r rune) int {
	return int(r - '0')
}
