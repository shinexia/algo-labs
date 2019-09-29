package _015_3sum

import (
	"reflect"
	"testing"
)

func TestThreeSum(t *testing.T) {
	cases := []struct {
		in     []int
		expect [][]int
	}{
		{[]int{-1, 0, 1, 2, -1, -4}, [][]int{{-1, -1, 2}, {-1, 0, 1}}},
		{[]int{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6}, [][]int{{-4,-2,6},{-4,0,4},{-4,1,3},{-4,2,2},{-2,-2,4},{-2,0,2}}},
	}
	for _, c := range cases {
		out := threeSum(c.in)
		if !reflect.DeepEqual(out, c.expect) {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, out, c.expect)
		}
	}
}
