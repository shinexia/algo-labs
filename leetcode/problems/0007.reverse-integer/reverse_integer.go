package _007_reverse_integer

import "math"

func reverse(x int) (y int) {
	for x != 0 {
		y = y * 10 + x % 10
		x = x / 10
		if y > math.MaxInt32 || y < math.MinInt32 {
			return 0
		}
	}
	return
}
