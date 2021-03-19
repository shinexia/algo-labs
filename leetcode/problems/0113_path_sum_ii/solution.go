package _113_path_sum_ii

import (
	"github.com/shinexia/algorithm-labs/leetcode/lib"
)

type TreeNode = lib.TreeNode

func pathSum(root *TreeNode, targetSum int) [][]int {
	if root == nil {
		return nil
	}
	return pathSum1(root, targetSum, nil, nil)
}

func pathSum1(root *TreeNode, targetSum int, path []int, out [][]int) [][]int {
	path = append(path, root.Val)
	targetSum -= root.Val
	if root.Left == nil && root.Right == nil {
		if targetSum == 0 {
			ret := make([]int, len(path))
			copy(ret, path)
			out = append(out, ret)
		}
		return out
	}
	if root.Left != nil {
		out = pathSum1(root.Left, targetSum, path, out)
	}
	if root.Right != nil {
		out = pathSum1(root.Right, targetSum, path, out)
	}
	return out
}
