package sorting

// Time : O(N^2)
// Space: O(N^2)
func BubbleSort(nums []int) {
	for i := range nums {
		for j := len(nums) - 1; j > i; j-- {
			if nums[j] < nums[j-1] {
				swap(nums, j, j-1)
			}
		}
	}
}
