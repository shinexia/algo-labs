package _029_divide_two_integers

import "math"

// https://leetcode.com/problems/divide-two-integers/

func divide(dividend int, divisor int) int {
	switch {
	case divisor == 0:
		panic("divide zero")
	case divisor == 1:
		return dividend
	case divisor == -1:
		if dividend == math.MinInt32 {
			return math.MaxInt32
		}
		return -dividend
	}
	sign := 1
	if dividend < 0 {
		dividend = -dividend
		sign = -sign
	}
	if divisor < 0 {
		divisor = -divisor
		sign = -sign
	}
	if divisor > dividend {
		return 0
	}
	p, f := divisor, 1
	for (p << 1) <= dividend {
		p <<= 1
		f <<= 1
	}
	quot, rem := 0, dividend
	for rem > 0 && p >= divisor {
		if rem >= p {
			rem -= p
			quot += f
		}
		p >>= 1
		f >>= 1
	}
	if sign == -1 {
		return -quot
	}
	return quot
}
