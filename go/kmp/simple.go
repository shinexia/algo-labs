package kmp

import "unsafe"

func simpleMatch(s, p string) int {
	sb := *(*[]byte)(unsafe.Pointer(&s))
	pb := *(*[]byte)(unsafe.Pointer(&p))
	for i := range sb {
		match := true
		for j, r := range pb {
			k := i + j
			if k >= len(sb) || sb[k] != r {
				match = false
				break
			}
		}
		if match {
			return i
		}
	}
	return -1
}
