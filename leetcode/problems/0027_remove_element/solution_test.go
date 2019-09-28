package _027_remove_element

import "testing"

func TestRemoveElement(t *testing.T) {
	cases := []struct {
		nums   []int
		val    int
		expect int
	}{
		{[]int{3, 2, 2, 3}, 3, 2},
		{[]int{0, 1, 2, 2, 3, 0, 4, 2}, 2, 5},
	}
	for _, c := range cases {
		out := removeElement(c.nums, c.val)
		if out != c.expect || !checkList(c.nums, c.val, c.expect) {
			t.Errorf("nums: %v, val: %v, out: %v, c.expect: %v", c.nums, c.val, out, c.expect)
		}
	}
}

func checkList(a []int, val int, length int) bool {
	if len(a) < length {
		return false
	}
	for _, x := range a[:length] {
		if x == val {
			return false
		}
	}
	return true
}
