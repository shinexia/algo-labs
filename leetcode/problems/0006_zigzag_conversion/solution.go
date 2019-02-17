package _006_zigzag_conversion

// https://leetcode.com/problems/zigzag-conversion/description/

func convert(s string, numRows int) string {
	if numRows < 2 {
		return s
	}
	N := len(s)
	base := 2 * numRows - 2
	out := make([]byte, len(s))
	var rems []int
	var index = 0
	for i := 0; i < numRows; i++ {
		if i != 0 && i != numRows - 1 {
			rems = []int{i, base - i}
		} else {
			rems = []int{i}
		}
		for j := 0; j < N; j += base {
			for _, rem := range rems {
				t := j + rem
				if t >= N || index >= N {
					break
				}
				out[index] = s[t]
				index++
			}
		}
	}
	return string(out)
}
