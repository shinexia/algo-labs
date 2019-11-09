package workspace

type ListNode struct {
	Val  int
	Next *ListNode
}

func NewListNode(nums []int) (head *ListNode) {
	var tail *ListNode
	for _, n := range nums {
		node := &ListNode{
			Val:  n,
			Next: nil,
		}
		if tail == nil {
			tail = node
			head = node
		} else {
			tail.Next = node
			tail = node
		}
	}
	return
}

func ListNodeToArray(head *ListNode) (nums []int) {
	for head != nil {
		nums = append(nums, head.Val)
		head = head.Next
	}
	return
}
