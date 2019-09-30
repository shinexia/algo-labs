package _015_3sum

// https://leetcode.com/problems/3sum/

import (
	"sort"
)

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	results := make([][]int, 0)
	n := len(nums)
	prevA := 1
	for i := 0; i < n-2; i++ {
		a := nums[i]
		if a > 0 {
			break
		}
		if a == prevA {
			continue
		}
		prevA = a
		li := i + 1
		ri := n - 1
		left := nums[li]
		right := nums[ri]
		for li < ri {
			sum := a + left + right
			if sum == 0 {
				ret := []int{a, left, right}
				results = append(results, ret)
				prevLeft := left
				for {
					li++
					left = nums[li]
					if left != prevLeft || li >= ri {
						break
					}
					prevLeft = left
				}
				prevRight := right
				for {
					ri--
					right = nums[ri]
					if li >= ri || right != prevRight {
						break
					}
					prevRight = right
				}
			} else if sum < 0 {
				li++
				left = nums[li]
			} else {
				ri--
				right = nums[ri]
			}
		}
	}
	return results
}
