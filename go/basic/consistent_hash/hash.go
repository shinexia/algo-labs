package consistent_hash

import (
	"sync"
	"sort"
	"strconv"
	"fmt"
)

type uints []uint32

// Len is the number of elements in the collection.
func (x uints) Len() int {
	return len(x)
}

// Less reports whether the element with
// index i should sort before the element with index j.
func (x uints) Less(i, j int) bool {
	return x[i] < x[j]
}

// Swap swaps the elements with indexes i and j.
func (x uints) Swap(i, j int) {
	x[i], x[j] = x[j], x[i]
}

type ConsistentHash struct {
	replica int // 虚拟节点数
	sortedHashes uints
	circle map[uint32]string // 将sortedHashes中hash值映射到具体的节点的ID
	members map[string]Node // 所有节点
	count int
	sync.RWMutex
}

func New(replica int) *ConsistentHash {
	return &ConsistentHash{
		replica: replica,
		circle: make(map[uint32]string, 0),
		members: make(map[string]Node, 0),
	}
}

func hashFunc(key string) uint32 {
	return Murmur3(key)
}

func nodeHashFunc(nodeId string, i int) uint32 {
	return hashFunc(strconv.Itoa(i) + nodeId)
}

func (c *ConsistentHash) String() string {
	return fmt.Sprintf("ConsistentHash(replica=%d, sortedHashes=%d, circle=%d, members=%d, count=%d)",
		c.replica, len(c.sortedHashes), len(c.circle), len(c.members), c.count)
}

func (c *ConsistentHash) Add(nodes... Node) {
	c.Lock()
	defer c.Unlock()
	for _, node := range nodes {
		nodeId := node.Id()
		for i := 0; i< c.replica; i++ {
			h := nodeHashFunc(nodeId, i)
			c.circle[h] = nodeId
		}
		c.members[nodeId] = node
		c.count++
	}
	c.updateSortedHashes()
}

func (c *ConsistentHash) Remove(nodes... Node) {
	c.Lock()
	defer c.Unlock()
	for _, node := range nodes {
		nodeId := node.Id()
		for i := 0; i< c.replica; i++ {
			h := nodeHashFunc(nodeId, i)
			delete(c.circle, h)
		}
		delete(c.members, nodeId)
		c.count--
	}
	c.updateSortedHashes()
}

func (c *ConsistentHash) Pick(key string) Node {
	c.RLock()
	defer c.RUnlock()
	if c.count == 0 {
		return nil
	}
	kh := hashFunc(key)
	i := c.search(kh)
	h := c.sortedHashes[i]
	return c.members[c.circle[h]]
}

func (c *ConsistentHash) search(h uint32) (i int) {
	fn := func(x int) bool {
		return c.sortedHashes[x] > h
	}
	i = sort.Search(len(c.sortedHashes), fn)
	if i >= len(c.sortedHashes) {
		i = 0
	}
	return
}

func (c *ConsistentHash) PickN(key string, n int) (res []Node) {
	c.RLock()
	defer c.RUnlock()
	if c.count == 0 {
		return nil
	}
	if c.count < n {
		n = c.count
	}
	res = make([]Node, n)
	resMap := make(map[string]bool, n)
	kh := hashFunc(key)
	start := c.search(kh)
	i, j := start, 0

	nodeId := c.circle[c.sortedHashes[i]]
	resMap[nodeId] = true
	res[j] = c.members[nodeId]
	i++
	j++
	for ; i != start; i++ {
		if i >= len(c.sortedHashes) {
			i = 0
		}
		nodeId := c.circle[c.sortedHashes[i]]
		if _, ok := resMap[nodeId]; !ok {
			res[j] = c.members[nodeId]
			resMap[nodeId] = true
			j++
		}
		if j >= n {
			break
		}
	}
	return
}

func (c *ConsistentHash) updateSortedHashes() {
	var hashes uints
	if m, n := cap(c.sortedHashes), len(c.circle); m / 4 > n || m < n {
		// reallocate
		hashes = make(uints, n)
	} else {
		// reuse
		hashes = c.sortedHashes[:n]
	}
	i := 0
	for k := range c.circle {
		hashes[i] = k
		i++
	}
	sort.Sort(hashes)
	c.sortedHashes = hashes
}
