package skiplist

import (
	"math/rand"
	"time"
	"fmt"
)

// Key 需要支持nil
type Key interface {
	Compare(other interface{}) int
}

var _NilKey Key = nil

// Value
type Value interface{}

// 节点信息
type node struct {
	key   Key
	value Value
	// 指向下一个节点
	forwards []*node
}

// level: [0, maxLevel]
func newNode(level int, key Key, value Value) (n *node) {
	n = &node{
		key:      key,
		value:    value,
		forwards: make([]*node, level),
	}
	for i := 0; i < level; i++ {
		n.forwards[i] = nil
	}
	return
}

func (n *node) String() string {
	if n == nil {
		return "<nil>"
	}
	forwards := make([]string, len(n.forwards))
	for i, f := range n.forwards {
		forwards[i] = fmt.Sprintf("%p", f)
	}
	return fmt.Sprintf("node(this=%s, key=%s, value=%s, forwards=%s)", fmt.Sprintf("%p", n), fmt.Sprint(n.key), fmt.Sprint(n.value), forwards)
}

// SkipList 跳表
type SkipList struct {
	maxLevel int
	level    int // 取值范围[0, maxLevel], forwards size = level, 0 表示无
	randg    *rand.Rand
	header   *node // header 不保存数据，key为nil时排在最右
}

// New 新建跳表
func New() *SkipList {
	return NewM(10)
}

func NewM(maxLevel int) (s *SkipList) {
	s = &SkipList{
		maxLevel: maxLevel,
		level:    0,
		randg:    rand.New(rand.NewSource(int64(time.Now().Nanosecond()))),
		header:   newNode(maxLevel, _NilKey, _NilKey),
	}
	return
}

// Find 查找key对应的值
func (l *SkipList) Find(key Key) Value {
	var p, q *node = l.header, nil
	for i := l.level - 1; i >= 0; i-- {
		for q = p.forwards[i]; q != nil && compareHelp(q.key, key) <= 0; p, q = q, q.forwards[i] {
			// nothing to do
		}
		if compareHelp(p.key, key) == 0 {
			return p.value
		}
	}
	return nil
}

// Put 添加新的值，如果之前已存在，则返回旧值
func (l *SkipList) Put(key Key, value Value) (old Value) {
	updates := make([]*node, 0, l.maxLevel)
	var p, q *node = l.header, nil
	for i := l.level - 1; i >= 0; i-- {
		for q = p.forwards[i]; q != nil && compareHelp(q.key, key) <= 0; p, q = q, q.forwards[i] {
			// nothing to do
		}
		if compareHelp(p.key, key) == 0 {
			old = p.value
			p.value = value
			return
		}
		updates = append(updates, p)
	}
	k := l.randomLevel()
	if k > l.level {
		for i := l.level; i < k; i ++ {
			updates = append(updates, l.header)
		}
		l.level = k
	}
	newNode := newNode(k, key, value)
	for i := 0; i < k; i++ {
		prev := updates[i]
		newNode.forwards[i] = prev.forwards[i]
		prev.forwards[i] = newNode
	}
	return
}

// Remove 删除key
func (l *SkipList) Remove(key Key) bool {
	prevList := make([]*node, l.level)
	var p, q, r *node = l.header, nil, l.header
	for i := l.level - 1; i >= 0; i-- {
		for q = p.forwards[i]; q != nil && compareHelp(q.key, key) <= 0; p, q = q, q.forwards[i] {
			r = p
		}
		prevList[i] = r
	}
	if compareHelp(p.key, key) != 0 {
		return false
	}
	headerEmptyCount := 0
	headerEmptyFlag := true
	for i := l.level - 1; i >= 0; i-- {
		prev := prevList[i]
		prev.forwards[i] = nil
		if i < len(p.forwards) {
			prev.forwards[i] = p.forwards[i]
		}
		if headerEmptyFlag {
			if prev == l.header && prev.forwards[i] == nil {
				headerEmptyCount++
			} else {
				headerEmptyFlag = false
			}
		}
	}
	if headerEmptyCount > 0 {
		for i := l.level - headerEmptyCount; i < l.level; i++ {
			l.header.forwards[i] = nil
		}
		l.level -= headerEmptyCount
	}
	return true
}

func (l *SkipList) String() string {
	var nodes = make([]*node, 0)
	for p := l.header; p != nil; p = p.forwards[0] {
		nodes = append(nodes, p)
	}
	return fmt.Sprintf("SkipList(maxLevel=%d, level=%d, nodes=%s)", l.maxLevel, l.level, nodes)
}

// 随机一个level: [1, l.maxLevel]
func (l *SkipList) randomLevel() int {
	return l.randg.Intn(l.maxLevel) + 1
}

// 防止a或b为nil
// key == nil 时，排在链表的最右边，header不保存数据
func compareHelp(a, b Key) int {
	if a == b {
		return 0
	} else if a == nil {
		return 1
	} else if b == nil {
		return -1
	} else {
		return a.Compare(b)
	}
}
