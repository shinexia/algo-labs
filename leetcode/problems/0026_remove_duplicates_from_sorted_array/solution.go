package _026_remove_duplicates_from_sorted_array

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

func removeDuplicates(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	prev := nums[0]
	sum := 0
	for _, n := range nums[1:] {
		if n != prev {
			sum += 1
			prev = n
			nums[sum] = n
		}
	}
	return sum + 1
}
