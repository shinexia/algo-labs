package _001_two_sum

import "testing"

// not discriminate nil array from empty array (eg. []int{})
func arrayEq(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, t := range a {
		if t != b[i] {
			return false
		}
	}
	return true
}

func TestTwoSum(t *testing.T) {
	tests := []struct{
		a []int
		target int
		expect []int
	}{
		{a: nil, target: 0, expect: nil},
		{a: []int{1}, target: 1, expect: nil},
		{a: []int{1, 2}, target: 1, expect: nil},
		{a: []int{1, 2}, target: 3, expect: []int{0, 1}},
		{a: []int{2, 7, 11, 15}, target: 22, expect: []int{1, 3}},
		{a: []int{2, 7, 11, 15}, target: 22, expect: []int{1, 3}},
	}
	for _, test := range tests {
		if out := twoSum(test.a, test.target); !arrayEq(out, test.expect) {
			t.Errorf("nums=%v, target=%d, out=%v, expect=%v", test.a, test.target, out, test.expect)
		}
	}
}
