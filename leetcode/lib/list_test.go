package lib

import (
	"testing"
)

func TestTreeNode(t *testing.T) {
	cases := []struct {
		nums    []int
		inorder []int
	}{
		{
			nums:    []int{5, Nil, 8, Nil, 4, 5, 1},
			inorder: []int{5, 8, 4, 5, 1},
		},
	}
	for _, c := range cases {
		tree := NewTreeNode(c.nums)
		nums := TreeNums(tree)
		if !ArrayEqualsInt(nums, c.nums) {
			t.Errorf("nums: %s, out: %s\n", ArrayToStringInt(c.nums), ArrayToStringInt(nums))
		}
		inorder := TreeInorderNums(tree)
		if !ArrayEqualsInt(inorder, c.inorder) {
			t.Errorf("inorder: %s, out: %s\n", ArrayToStringInt(c.inorder), ArrayToStringInt(inorder))
		}
	}
}
