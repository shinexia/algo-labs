package search

import "testing"

func TestBinarySearch(t *testing.T) {
	tests := []struct {
		a      []int
		key    int
		expect int
	}{
		{a: nil, key: 3, expect: NotFound},
		{a: []int{1, 2}, key: 3, expect: NotFound},
		{a: []int{1, 2, 3, 4, 5}, key: 3, expect: 2},
		{a: []int{1, 2, 3, 4, 5}, key: 4, expect: 3},
	}
	for _, test := range tests {
		if out := BinarySearch(test.a, test.key); out != test.expect {
			t.Errorf("a=%v, key=%d, out=%d, expect=%d", test.a, test.key, out, test.expect)
		}
	}
}
