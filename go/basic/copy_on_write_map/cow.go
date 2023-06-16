package copy_on_write_map

import (
	"sync"
	"sync/atomic"
)

// CopyOnWriteMap 写时加锁，适用于读多写少的场景
type CopyOnWriteMap struct {
	m      atomic.Value
	lock   sync.Mutex
	loader Loader
}

type Loader func(key interface{}) interface{}

func New() *CopyOnWriteMap {
	return NewF(nil)
}

func NewF(loader Loader) *CopyOnWriteMap {
	m := make(map[interface{}]interface{}, 0)
	s := &CopyOnWriteMap{
		loader: loader,
	}
	s.m.Store(&m)
	return s
}

func (c *CopyOnWriteMap) Get(key interface{}) interface{} {
	m := *c.m.Load().(*map[interface{}]interface{})
	return m[key]
}

func (c *CopyOnWriteMap) GetE(key interface{}) (interface{}, bool) {
	m := *c.m.Load().(*map[interface{}]interface{})
	v, ok := m[key]
	return v, ok
}

func (c *CopyOnWriteMap) Put(key interface{}, value interface{}) interface{} {
	old, _ := c.PutE(key, value)
	return old
}

func (c *CopyOnWriteMap) PutE(key interface{}, value interface{}) (interface{}, bool) {
	c.lock.Lock()
	defer c.lock.Unlock()
	return c.doPutE(key, value)
}

func (c *CopyOnWriteMap) GetOrCreate(key interface{}) interface{} {
	m := *c.m.Load().(*map[interface{}]interface{})
	v, ok := m[key]
	if ok {
		return v
	}
	c.lock.Lock()
	defer c.lock.Unlock()
	if c.loader == nil {
		panic("CopyOnWriteMap#loader is nil")
	}
	value := c.loader(key)
	c.doPutE(key, value)
	return value
}

// it's the caller's responsibility to sync
func (c *CopyOnWriteMap) doPutE(key interface{}, value interface{}) (interface{}, bool) {
	oldM := *c.m.Load().(*map[interface{}]interface{})
	old, ok := oldM[key]
	N := len(oldM)
	if !ok {
		N++
	}
	newM := make(map[interface{}]interface{}, N)
	for k, v := range oldM {
		newM[k] = v
	}
	newM[key] = value
	c.m.Store(&newM)
	return old, ok
}
