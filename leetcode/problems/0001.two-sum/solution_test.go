package _001_two_sum

import "testing"

func TestTwoSum(t *testing.T) {
	nums := []int{2, 7, 11, 15}
	r := twoSum(nums, 22)
	if len(r) != 2 || r[0] != 1 || r[1] != 3 {
		t.Error()
	}
}
