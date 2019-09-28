package _013_roman_to_integer

import (
	"log"
)

// https://leetcode.com/problems/roman-to-integer/

var symbols map[rune]int = make(map[rune]int)

func init() {
	symbols['I'] = 1
	symbols['V'] = 5
	symbols['X'] = 10
	symbols['L'] = 50
	symbols['C'] = 100
	symbols['D'] = 500
	symbols['M'] = 1000
}

func romanToInt(s string) int {
	if len(s) == 0 {
		return 0
	}
	nums := make([]int, len(s))
	for i, r := range []rune(s) {
		n, ok := symbols[r]
		if !ok {
			log.Panicf("invalid symbol: %v\n", r)
		}
		nums[i] = n
	}
	length := len(nums) - 1
	sum := nums[length]
	for i, n := range nums[:length] {
		next := nums[i+1]
		if n < next {
			sum -= n
		} else {
			sum += n
		}
	}
	return sum
}
