package workspace

import "sort"

/*
 * @lc app=leetcode.cn id=31 lang=golang
 *
 * [31] 下一个排列
 */
// @lc code=start
func nextPermutation(nums []int) {
	n := len(nums)
	if n <= 1 {
		return
	}
	if n == 2 {
		swap(nums, 0, 1)
		return
	}
	var i = n - 2
	for i >= 0 {
		if nums[i] < nums[i+1] {
			break
		}
		i--
	}
	if i < 0 {
		sort.Sort(sort.IntSlice(nums))
		return
	}
	var j = n - 1
	for j > i {
		if nums[j] > nums[i] {
			break
		}
		j--
	}
	swap(nums, i, j)
	sort.Sort(sort.IntSlice(nums[i+1:]))
}

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

// @lc code=end
