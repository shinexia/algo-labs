package workspace

/*
 * @lc app=leetcode id=10 lang=golang
 *
 * [10] Regular Expression Matching
 */

// @lc code=start

import "fmt"

// EndSentinel end sentinel
var EndSentinel = &treeNode{}

type treeNode struct {
	Val  rune
	Next []*treeNode
}

func newMachine(p string) (start *treeNode, err error) {
	start = &treeNode{}
	tail := []*treeNode{start}
	var (
		i  = 0
		pr = []rune(p)
		N  = len(pr)
	)
	for i < N {
		r := pr[i]
		if r == '*' {
			err = fmt.Errorf("invalid pattern, i: %v, r: %v", i, r)
			return
		}
		next := &treeNode{
			Val:  r,
			Next: nil,
		}
		i++
		if i < N && pr[i] == '*' {
			i++
			if i < N && pr[i] == '*' {
				err = fmt.Errorf("invalid pattern, i: %v, r: %v", i, r)
				return
			}
			tail = append(tail, next)
			for _, t := range tail {
				t.Next = append(t.Next, next)
			}
		} else {
			for _, t := range tail {
				t.Next = append(t.Next, next)
			}
			tail = []*treeNode{next}
		}
	}
	for _, child := range tail {
		child.Next = append(child.Next, EndSentinel)
	}
	return
}

func doMatch(m *treeNode, rs []rune) bool {
	if len(rs) == 0 {
		for _, child := range m.Next {
			if child == EndSentinel {
				return true
			}
		}
		return false
	}
	r := rs[0]
	rs = rs[1:]
	for _, child := range m.Next {
		if child != EndSentinel && (child.Val == r || child.Val == '.') {
			if doMatch(child, rs) {
				return true
			}
		}
	}
	return false
}

func isMatch(s string, p string) bool {
	m, err := newMachine(p)
	if err != nil {
		return false
	}
	return doMatch(m, []rune(s))
}

// @lc code=end
