package _016_3sum_closest

import (
	"math"
	"sort"
)

// https://leetcode.com/problems/3sum-closest/

func threeSumClosest(nums []int, target int) int {
	if len(nums) < 3 {
		return 0
	}
	sort.Ints(nums)
	var answer int
	var prevDiff = math.MaxInt32
	n := len(nums)
	for i := 0; i < n-2; i++ {
		a := nums[i]
		j, k := i+1, n-1
		left, right := nums[j], nums[k]
		for j < k {
			sum := a + left + right
			diff := sum - target
			absDiff := abs(sum - target)
			if absDiff < prevDiff {
				answer = sum
				prevDiff = absDiff
			}
			if diff == 0 {
				return answer
			} else if diff < 0 {
				j++
				left = nums[j]
			} else {
				k--
				right = nums[k]
			}
		}
	}
	return answer
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
