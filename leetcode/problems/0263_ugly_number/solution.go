package _263_ugly_number

// https://leetcode.com/problems/ugly-number/

func isUgly(num int) bool {
	if num < 1 {
		return false
	}
	for num & 1 == 0 {
		num >>= 1
	}
	for num % 3 == 0 {
		num /= 3
	}
	for num % 5 == 0 {
		num /= 5
	}
	return num == 1
}
