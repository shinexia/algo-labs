package workspace

import "testing"

func TestNextPermutation(t *testing.T) {
	cases := []struct {
		a []int
		b []int
	} {
		{[]int{1, 2, 3}, []int{1, 3, 2}},
		{[]int{3, 2, 1}, []int{1, 2, 3}},
		{[]int{1, 1, 5}, []int{1, 5, 1}},
		{[]int{5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5}},
		{[]int{1, 2, 4, 6, 5, 3}, []int{1, 2, 5, 3, 4, 6}},
	}
	for _, c := range cases {
		nextPermutation(c.a)
		if !arrayEquals(c.a, c.b) {
			t.Errorf("a: %v, expect: %v\n", c.a, c.b)
		}
	}
}
