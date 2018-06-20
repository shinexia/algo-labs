package _004_find_median_sorted_arrays

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// Time: O(log(m + n))
func findMedianSortedArrays(n1 []int, n2 []int) float64 {
	N1 := len(n1)
	if N1 == 0 {
		return findMedianSortedArray(n2, len(n2))
	}
	N2 := len(n2)
	if N2 == 0 {
		return findMedianSortedArray(n1, N1)
	}
	p1 := n1[(N1 - 1) >> 1]
	p2 := n2[(N2 + 1) >> 1]
}

func findMedianSortedArray(nums []int, N int) (out float64) {
	p1 := (N - 1) >> 1
	if N & 0x1 == 0 && N > 1 {
		out = float64(nums[p1] + nums[p1 + 1]) / 2.0
	} else if N > 0 {
		out = float64(nums[p1])
	}
	return
}
