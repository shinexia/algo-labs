package _018_4sum

import (
	"reflect"
	"testing"
)

func Test4Sum(t *testing.T) {
	cases := []struct {
		in     []int
		target int
		expect [][]int
	}{
		{[]int{1, 0, -1, 0, -2, 2}, 0, [][]int{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}},
		{[]int{-1, 0, 1, 2, -1, -4}, -1, [][]int{{-4, 0, 1, 2}, {-1, -1, 0, 1}}},
		{[]int{1, -2, -5, -4, -3, 3, 3, 5}, -11, [][]int{{-5, -4, -3, 1}}},
		{[]int{-3, 5, 3, -1, 5, -2, 0, -1}, -3, [][]int{{-3, -2, -1, 3}}},
	}
	for _, c := range cases {
		out := fourSum(c.in, c.target)
		if !reflect.DeepEqual(out, c.expect) {
			t.Errorf("in: %v, target: %v, out: %v, expect: %v", c.in, c.target, out, c.expect)
		}
	}
}
