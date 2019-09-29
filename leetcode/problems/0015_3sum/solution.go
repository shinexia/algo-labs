package _015_3sum

// https://leetcode.com/problems/3sum/

import (
	"reflect"
	"sort"
)

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	results := make([][]int, 0)
	var prev []int
	n := len(nums)
	for i, a := range nums[:n-2] {
		if a > 0 {
			break
		}
		li := i + 1
		ri := n - 1
		left := nums[li]
		right := nums[ri]
		for li < ri {
			sum := a + left + right
			switch {
			case sum == 0:
				ret := []int{a, left, right}
				if !reflect.DeepEqual(ret, prev) {
					results = append(results, ret)
					prev = ret
				}
				li++
				left = nums[li]
				ri--
				right = nums[ri]
			case sum < 0:
				li++
				left = nums[li]
			case sum > 0:
				ri--
				right = nums[ri]
			}
		}
	}
	return results
}
