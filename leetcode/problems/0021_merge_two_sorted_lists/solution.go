package _021_merge_two_sorted_lists

// https://leetcode.com/problems/merge-two-sorted-lists/
type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) (head *ListNode) {
	var prev *ListNode
	for l1 != nil || l2 != nil {
		if l1 == nil || (l2 != nil && l2.Val < l1.Val) {
			l2, l1 = l1, l2
		}
		node := &ListNode{
			Val: l1.Val,
		}
		if prev == nil {
			head = node
		} else {
			prev.Next = node
		}
		prev = node
		l1 = l1.Next
	}
	return
}
