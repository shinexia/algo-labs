package problems

/*
 * @lc app=leetcode id=66 lang=golang
 *
 * [66] Plus One
 */

// @lc code=start
func plusOne(digits []int) []int {
	n := len(digits)
	for i := n - 1; i >= 0; i-- {
		s := digits[i] + 1
		if s >= 10 {
			digits[i] = s - 10
			if i == 0 {
				digits = append([]int{1}, digits...)
			}
		} else {
			digits[i] = s
			break
		}
	}
	return digits
}

// @lc code=end
