package _026_remove_duplicates_from_sorted_array

import "testing"

func TestRemoveDuplicates(t *testing.T) {
	cases := []struct {
		in     []int
		expect int
	}{
		{in: []int{}, expect: 0},
		{in: []int{1}, expect: 1},
		{in: []int{1, 1}, expect: 1},
		{in: []int{1, 1, 2}, expect: 2},
		{in: []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, expect: 5},
	}
	for _, c := range cases {
		out := removeDuplicates(c.in)
		if out != c.expect || !checkList(c.in, c.expect) {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}

func checkList(in []int, length int) bool {
	if len(in) < length {
		return false
	}
	if length <= 1 {
		return true
	}
	prev := in[0]
	for _, a := range in[1:length] {
		if a <= prev {
			return false
		}
		prev = a
	}
	return true
}
