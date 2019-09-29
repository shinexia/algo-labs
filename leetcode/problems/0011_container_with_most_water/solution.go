package _011_container_with_most_water

// https://leetcode.com/problems/container-with-most-water/

func maxArea(height []int) int {
	result := 0
	li := 0
	ri := len(height) - 1
	left := height[li]
	right := height[ri]
	for li < ri {
		var area int
		if left < right {
			area = (ri - li) * left
			li++
			left = height[li]
		} else {
			area = (ri - li) * right
			ri--
			right = height[ri]
		}
		if area > result {
			result = area
		}
	}
	return result
}
