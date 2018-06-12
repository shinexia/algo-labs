package _003_longest_substring_without_repeating_characters

// Time : O(n)
// Space: O(k), k = max
//
// m 保存 r rune 在 s 中的位置
// abcbdef 到第二个b时，发现重复的，且idx=1，则删除m中所有位置小于idx的k，而b对应的位置更新为3
func LengthOfLongestSubstring(s string) (max int) {
	var m = make(map[rune]int, 0)
	for i, r := range s {
		idx, ok := m[r]
		if ok {
			n := len(m)
			if n > max {
				max = n
			}
			for k, v := range m {
				if v < idx {
					delete(m, k)
				}
			}
		}
		m[r] = i
	}
	// 最后剩余的一个
	n := len(m)
	if n > max {
		max = n
	}
	return
}
