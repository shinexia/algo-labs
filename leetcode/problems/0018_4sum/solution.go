package _018_4sum

import "sort"

// https://leetcode.com/problems/4sum/

func fourSum(nums []int, target int) [][]int {
	n := len(nums)
	if n < 4 {
		return [][]int{}
	}
	sort.Ints(nums)
	var answers [][]int
	prevA := nums[0] + 1
	for i := 0; i < n-3; i++ {
		a := nums[i]
		if a == prevA {
			continue
		}
		prevA = a
		prevB := nums[i+1] + 1
		for j := i + 1; j < n-2; j++ {
			b := nums[j]
			if b == prevB {
				continue
			}
			prevB = b
			answers = twoSum(nums[j+1:], target-a-b, a, b, answers)
		}
	}
	return answers
}

func twoSum(nums []int, target int, a, b int, answers [][]int) [][]int {
	n := len(nums)
	li := 0
	ri := n - 1
	left := nums[li]
	right := nums[ri]
	for li < ri {
		sum := left + right - target
		if sum == 0 {
			ret := []int{a, b, left, right}
			answers = append(answers, ret)
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
	return answers
}
