package skiplist

import (
	"fmt"
	"testing"
)

const (
	op_nothing = iota
	op_put
	op_remove
)

type expect struct {
	s     []pair      // 链表全部的 kv 结构
	r     interface{} // op 操作的结果
	key   interface{} // key
	value interface{} // 上面的 key 对应的 value 应该与此相同
}

type pair struct {
	key   interface{}
	value interface{}
}

func listEq(s *SkipList, pairs []pair) (out bool) {
	out = true
	s.Inspect(func(i int, key Key, value Value) bool {
		if i >= len(pairs) {
			out = false
			return false
		}
		p := pairs[i]
		var k Key
		if p.key != nil {
			k = Int(p.key.(int))
		}
		if compareHelp(k, key) != 0 || p.value != value {
			out = false
			return false
		}
		return true
	})
	return
}

func TestSkipList(t *testing.T) {
	tests := []struct {
		op     int // 执行某种操作
		key    interface{}
		value  interface{}
		expect expect
	}{
		{op: op_nothing, expect: expect{s: nil, key: nil, value: nil}},
		{op: op_put, key: 0, value: 2, expect: expect{s: []pair{{0, 2}}, r: nil, key: 0, value: 2}},
		{op: op_put, key: nil, value: 3, expect: expect{s: []pair{{0, 2}, {nil, 3}}, r: nil, key: nil, value: 3}},
		{op: op_put, key: 0, value: 4, expect: expect{s: []pair{{0, 4}, {nil, 3}}, r: 2, key: 0, value: 4}},
		{op: op_nothing, expect: expect{s: []pair{{0, 4}, {nil, 3}}, key: 1, value: nil}},
		{op: op_remove, key: 1, expect: expect{s: []pair{{0, 4}, {nil, 3}}, r: false, key: 1, value: nil}},
		{op: op_remove, key: 0, expect: expect{s: []pair{{nil, 3}}, r: true, key: 0, value: nil}},
		{op: op_remove, key: nil, expect: expect{s: []pair{}, r: true, key: nil, value: nil}},
	}

	s := New()
	for _, test := range tests {
		var tk Key
		if test.key != nil {
			tk = NewInt(test.key.(int))
		}
		var r interface{}
		switch test.op {
		case op_put:
			r = s.Put(tk, test.value)
		case op_remove:
			r = s.Remove(tk)
		case op_nothing:
		default:
			panic("invalid op type:" + fmt.Sprint(test.op))
		}
		if !listEq(s, test.expect.s) {
			t.Errorf("s=%v, expect.s=%v", s, test.expect.s)
		}
		if r != test.expect.r {
			t.Errorf("s=%v, r=%v, expect.r=%v", s, r, test.expect.r)
		}
		var k Key
		if test.expect.key != nil {
			k = NewInt(test.expect.key.(int))
		}
		if r := s.Find(k); r != test.expect.value {
			t.Errorf("s=%v, out=%v, expect.key=%v, expect.value=%v", s, r, test.expect.key, test.expect.value)
		}
	}
}
