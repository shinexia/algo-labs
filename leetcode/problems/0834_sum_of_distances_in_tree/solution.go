package _834_sum_of_distances_in_tree

type Node struct {
	val         int
	children    []*Node
	parent      *Node
	sum         int
	numChildren int
}

func (this *Node) addChild(child *Node) {
	this.children = append(this.children, child)
}

func (this *Node) removeChild(child *Node) {
	var i = -1
	for j, node := range this.children {
		if child == node {
			i = j
			break
		}
	}
	if i < 0 {
		return
	}
	this.children[i] = this.children[len(this.children)-1]
	this.children = this.children[:len(this.children)-1]
}

func (this *Node) setParent(parent *Node) {
	this.parent = parent
}

func setParent(root *Node, N int) {
	nodes := []*Node{root}
	stack := make([]*Node, 0, N)
	depth := 1
	for {
		stack = append(stack, nodes...)
		var next []*Node
		for _, node := range nodes {
			for _, child := range node.children {
				child.removeChild(node)
				child.setParent(node)
				next = append(next, child)
			}
		}
		if next == nil {
			break
		}
		nodes = next
		root.sum += len(nodes) * depth
		depth++
	}
	for i := 0; i < N; i++ {
		node := stack[N-i-1]
		if len(node.children) == 0 {
			node.numChildren = 0
		} else {
			for _, child := range node.children {
				node.numChildren += child.numChildren
			}
			node.numChildren += len(node.children)
		}
	}
}

func calcSum(root *Node, N int) {
	nodes := root.children
	for {
		var next []*Node
		for _, node := range nodes {
			node.sum += node.parent.sum + (N - node.numChildren - 2) - node.numChildren
			next = append(next, node.children...)
		}
		if next == nil {
			break
		}
		nodes = next
	}
}

func sumOfDistancesInTree(N int, edges [][]int) []int {
	if N <= 1 {
		return []int{0}
	}
	nodes := make([]*Node, N)
	for i := range nodes {
		nodes[i] = &Node{
			val: i,
		}
	}
	for _, e := range edges {
		a, b := nodes[e[0]], nodes[e[1]]
		a.addChild(b)
		b.addChild(a)
	}
	setParent(nodes[0], N)
	calcSum(nodes[0], N)
	ret := make([]int, N)
	for i := 0; i < N; i++ {
		ret[i] = nodes[i].sum
	}
	return ret
}
