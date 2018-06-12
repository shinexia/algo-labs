package _001_two_sum

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
