package lib

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func TreeLen(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + TreeLen(root.Left) + TreeLen(root.Right)
}

func TreeDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + MaxInt(TreeDepth(root.Left), TreeDepth(root.Right))
}

func TreeInorderNums(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	return _treeInorderNums(root, nil)
}

func _treeInorderNums(root *TreeNode, out []int) []int {
	if root == nil {
		return out
	}
	out = append(out, root.Val)
	out = _treeInorderNums(root.Left, out)
	return _treeInorderNums(root.Right, out)
}

func TreeNums(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	out := _treeNums([]*TreeNode{root}, nil)
	var offset = len(out) - 1
	for ; offset >= 0; offset-- {
		if out[offset] != Nil {
			break
		}
	}
	return out[:offset+1]
}

func _treeNums(root []*TreeNode, out []int) []int {
	var nodes []*TreeNode
	for _, node := range root {
		if node == nil {
			out = append(out, Nil)
		} else {
			out = append(out, node.Val)
			nodes = append(nodes, node.Left)
			nodes = append(nodes, node.Right)
		}
	}
	if nodes == nil {
		return out
	}
	return _treeNums(nodes, out)
}

func NewTreeNode(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	root := &TreeNode{
		Val: nums[0],
	}
	_newTreeNode([]*TreeNode{root}, nums[1:])
	return root
}

func _newTreeNode(root []*TreeNode, nums []int) {
	var nodes []*TreeNode
	rootLen := len(root)
	numLen := len(nums)
	j := 0
	for i := 0; i < rootLen && j < numLen; i++ {
		node := root[i]
		l := nums[j]
		if l == Nil {
			node.Left = nil
		} else {
			node.Left = &TreeNode{
				Val: l,
			}
			nodes = append(nodes, node.Left)
		}
		j++
		if j >= numLen {
			break
		}
		r := nums[j]
		if r == Nil {
			node.Right = nil
		} else {
			node.Right = &TreeNode{
				Val: r,
			}
			nodes = append(nodes, node.Right)
		}
		j++
	}
	if nodes == nil {
		return
	}
	_newTreeNode(nodes, nums[j:])
}
