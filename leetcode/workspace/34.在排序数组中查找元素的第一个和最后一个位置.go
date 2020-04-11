package workspace

/*
 * @lc app=leetcode.cn id=34 lang=golang
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
func searchRange(nums []int, target int) []int {
	r := searchRange0(nums, target, 0, len(nums)-1)
	if r == nil {
		return []int{-1, -1}
	}
	return r
}

func searchRange0(nums []int, target, start, end int) []int {
	if start > end || target < nums[start] || target > nums[end] {
		return nil
	}
	if start == end {
		if target == nums[start] {
			return []int{start, start}
		}
		return nil
	}
	mid := (start + end) / 2
	if target < nums[mid] {
		return searchRange0(nums, target, start, mid-1)
	}
	if target > nums[mid] {
		return searchRange0(nums, target, mid+1, end)
	}
	i := searchRangeLeft(nums, target, start, mid)
	j := searchRangeRight(nums, target, mid, end)
	return []int{i, j}
}

func searchRangeLeft(nums []int, target, start, end int) int {
	if start >= end {
		return end
	}
	if nums[start] == target {
		return start
	}
	mid := (start + end) / 2
	if nums[mid] < target {
		return searchRangeLeft(nums, target, mid+1, end)
	}
	// else nums[mid] == target
	return searchRangeLeft(nums, target, start, mid)
}

func searchRangeRight(nums []int, target, start, end int) int {
	if start >= end {
		return start
	}
	if nums[end] == target {
		return end
	}
	mid := (start + end + 1) / 2
	if nums[mid] > target {
		return searchRangeRight(nums, target, start, mid-1)
	}
	// else nums[mid] == target
	return searchRangeRight(nums, target, mid, end)
}

// @lc code=end
