package kmp

import "unsafe"

func kmpMatch(s, p string) int {
	sb := *(*[]byte)(unsafe.Pointer(&s))
	pb := *(*[]byte)(unsafe.Pointer(&p))
	pmt := kmpPartialMatchTable(pb)
	var (
		sn = len(sb)
		pn = len(pb)
	)
	var i, j int
	for i < sn && j < pn {
		if j == -1 || s[i] == p[j] {
			i++
			j++
		} else {
			j = pmt[j]
		}
	}
	if j == pn {
		return i - j
	}
	return -1
}

// 这是一个递归，由[0, i]的值，推导i+1的值，初始值next[0] = -1
func kmpPartialMatchTable(pb []byte) []int {
	next := make([]int, len(pb))
	next[0] = -1
	var (
		i = 1
		k = 0
	)
	for i < len(pb) - 1 {
		if k == -1 || pb[i] == pb[k] {
			i++
			k++
			next[i] = k
		} else {
			k = next[k]
		}
	}
	return next
}
