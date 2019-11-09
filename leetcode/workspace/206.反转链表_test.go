package workspace

import (
	"fmt"
	"testing"
)

func TestReverseList(t *testing.T) {
	cases := []struct {
		nums []int
	}{
		{[]int{1, 2, 3, 4, 5}},
	}
	for _, c := range cases {
		out := ListNodeToArray(reverseList(NewListNode(c.nums)))
		fmt.Println(out)
	}
}
