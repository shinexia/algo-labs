package _264_nth_ugly_number

import "testing"

func TestNthUglyNumber(t *testing.T) {
	index := 0
	for i := 1; i < 2000; i++ {
		if isUgly(i) {
			index++
			if out := nthUglyNumber(index); out != i {
				t.Errorf("index: %v, out: %v, expect: %v", index, out, i)
				break
			}
		}
	}
}

func TestNthUglyNumber0(t *testing.T) {
	nthUglyNumber(20)
}

func isUgly(num int) bool {
	if num < 1 {
		return false
	}
	for num&1 == 0 {
		num >>= 1
	}
	for num%3 == 0 {
		num /= 3
	}
	for num%5 == 0 {
		num /= 5
	}
	return num == 1
}
