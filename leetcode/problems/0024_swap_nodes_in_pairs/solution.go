package _024_swap_nodes_in_pairs

// https://leetcode.com/problems/swap-nodes-in-pairs/

type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	iter := dummy
	for iter.Next != nil && iter.Next.Next != nil {
		first := iter.Next
		iter.Next = iter.Next.Next
		first.Next = iter.Next.Next
		iter.Next.Next = first
		iter = first
	}
	return dummy.Next
}
