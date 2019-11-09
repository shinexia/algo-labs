package workspace

/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	next := head.Next
	head.Next = nil
	for next != nil {
		println(head.Val)
		t := next.Next
		next.Next = head
		head = next
		next = t
	}
	return head
}

// @lc code=end
