package workspace

/*
 * @lc app=leetcode.cn id=440 lang=golang
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start

func findKthNumber(n int, k int) int {
	count := 0
	for i := 1; i < 10; i++ {
		j := i
		base := 1
		for j <= n {
			nj := j * 10
			if nj <= n {
				count += base
				if count >= k {
					return j + k - (count - base) - 1
				}
			} else {
				d := n - j + 1
				if d > base {
					d = base
				}
				count += d
				if count >= k {
					return j + k - (count - d) - 1 // = base + (k - (count - d))
				}
				break
			}
			j = nj
			base *= 10
		}
	}
	return 0
}

func findKthNumber0(n int, k int) int {
	base := 1
	base1 := 10
	count := 0
	for n >= base1 {
		count += base
		base = base1
		base1 *= 10
	}
	bk := base * k
	if n >= bk+base {
		count += base
	} else if n >= bk {
		count += n - bk + 1
	}
	return count
}

// @lc code=end
