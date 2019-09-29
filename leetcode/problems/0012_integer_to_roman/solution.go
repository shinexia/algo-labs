package _012_integer_to_roman

// https://leetcode.com/problems/integer-to-roman/

func intToRoman(num int) string {
	var s string
	idx := 0
	for num > 0 {
		digit := num % 10
		s = digitToRoman(digit, symbols[idx], symbols[idx+1], symbols[idx+2]) + s
		num /= 10
		idx += 2
	}
	return s
}

var symbols = []string{"I", "V", "X", "L", "C", "D", "M", "", ""}

func digitToRoman(digit int, i, v, x string) string {
	switch {
	case digit == 0:
		return ""
	case digit < 4:
		return repeat(i, digit)
	case digit == 4:
		return i + v
	case digit == 5:
		return v
	case digit < 9:
		return v + repeat(i, digit-5)
	case digit == 9:
		return i + x
	default:
		return ""
	}
}

func repeat(s string, repeat int) string {
	switch repeat {
	case 1:
		return s
	case 2:
		return s + s
	case 3:
		return s + s + s
	default:
		for i := 1; i < repeat; i++ {
			s += s
		}
		return s
	}
}
