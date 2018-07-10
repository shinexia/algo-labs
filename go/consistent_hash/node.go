package consistent_hash


type Node interface {

	// 唯一标识，用于判断两个节点是否相等，以及生成hash
	Id() string

	// 权重
	Weight() int

}

type nodeImpl struct {
	name   string
	weight int
}

func (s *nodeImpl) Id() string {
	return s.name
}

func (s *nodeImpl) Weight() int {
	return s.weight
}

func (s *nodeImpl) String() string {
	return "Node(id=" + s.name + ")"
}

func NewNode(name string) Node {
	return &nodeImpl{
		name: name,
	}
}

func NewNodeW(name string, weight int) Node {
	return &nodeImpl{
		name:   name,
		weight: weight,
	}
}
