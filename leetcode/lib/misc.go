package lib

import (
	"math"
	"strconv"
)

const (
	Nil = math.MinInt64
)

func MaxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func ArrayEqualsInt(a, b []int) bool {
	an, bn := len(a), len(b)
	if an != bn {
		return false
	}
	if an == 0 {
		return true
	}
	for i, x := range a {
		if b[i] != x {
			return false
		}
	}
	return true
}

func ArraysEqualsInt(a, b [][]int) bool {
	an, bn := len(a), len(b)
	if an != bn {
		return false
	}
	if an == 0 {
		return true
	}
	for i, x := range a {
		if !ArrayEqualsInt(b[i], x) {
			return false
		}
	}
	return true
}

func ArrayToStringInt(out []int) string {
	s := "["
	for i, n := range out {
		if i > 0 {
			s += ","
		}
		if n == Nil {
			s += "null"
		} else {
			s += strconv.Itoa(n)
		}
	}
	return s + "]"
}

func ArraysToStringInt(out [][]int) string {
	s := "["
	for i, n := range out {
		if i > 0 {
			s += ","
		}
		if n == nil {
			s += "null"
		} else {
			s += ArrayToStringInt(n)
		}
	}
	return s + "]"
}
