package _019_remove_nth_node_from_end_of_lists

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	L := 0
	t := head
	for t != nil {
		t = t.Next
		L++
	}
	if n > L {
		return head
	} else if n == L {
		return head.Next
	} else {
		I := L - n - 1
		t = head
		for i := 0; i < I; i++ {
			t = t.Next
		}
		t.Next = t.Next.Next
		return head
	}
}
