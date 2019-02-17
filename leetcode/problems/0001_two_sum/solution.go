package _001_two_sum

// https://leetcode.com/problems/two-sum/description/

// Time : O(n^2)
// Space: O(1)
func twoSum(nums []int, target int) (out []int) {
	N := len(nums)
	for i, n := range nums {
		t := target - n
		for j := i + 1; j < N; j ++ {
			if nums[j] == t {
				out = []int{i, j}
				return
			}
		}
	}
	return
}
