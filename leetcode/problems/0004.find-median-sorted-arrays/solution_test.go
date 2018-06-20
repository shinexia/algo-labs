package _004_find_median_sorted_arrays

import (
	"testing"
	"math"
)

func TestFindMedianSortedArrays(t *testing.T) {
	tests := []struct {
		a      []int
		b      []int
		expect float64
	} {
		{a: []int{}, b: []int{1}, expect: 1},
		{a: []int{1}, b: []int{2}, expect: 1.5},
		{a: []int{1}, b: []int{2, 3}, expect: 2},
		{a: []int{1, 2}, b: []int{3, 4}, expect: 2.5},
		{a: []int{4, 5}, b: []int{1, 2, 3}, expect: 3},
	}

	for _, test := range tests {
		if o := findMedianSortedArrays(test.a, test.b); math.Abs(o - test.expect) > 0.000001 {
			t.Errorf("a=%v, b=%v, out=%f, expect=%f", test.a, test.b, o, test.expect)
		}
	}
}