package _002_add_two_numbers

// https://leetcode.com/problems/add-two-numbers/description/

type ListNode struct {
	Val  int
	Next *ListNode
}

// Time : O(n)
// Space: O(n)
func addTwoNumbers(l1 *ListNode, l2 *ListNode) (out *ListNode) {
	var carry int
	var val int
	var prev *ListNode
	for {
		val = carry
		b := false
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
			b = true
		}
		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
			b = true
		}
		if !b && carry == 0 {
			return
		}
		carry = 0
		if val >= 10 {
			carry = 1
			val = val - 10
		}
		cur := &ListNode{Val: val}
		if prev == nil {
			prev = cur
			out = cur
		} else {
			prev.Next = cur
			prev = cur
		}
	}
}
