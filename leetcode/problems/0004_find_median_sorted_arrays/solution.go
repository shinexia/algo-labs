package _004_find_median_sorted_arrays

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// Time: O(log(m + n))
func findMedianSortedArrays(A []int, B []int) (out float64) {
	m := len(A)
	n := len(B)
	if m > n {
		// 保证 m <= n
		m, n = n, m
		A, B = B, A
	}
	var (
		iMin    = 0
		iMax    = m
		halfLen = (m + n + 1) / 2
	)
	for iMin <= iMax {
		i := (iMin + iMax) / 2
		j := halfLen - i
		if i < iMax && B[j-1] > A[i] {
			// i is too small
			iMin = iMin + 1
		} else if i > iMin && A[i-1] > B[j] {
			// i is too big
			iMax = iMax - 1
		} else {
			// i is perfect
			maxLeft := 0
			if i == 0 {
				maxLeft = B[j-1]
			} else if j == 0 {
				maxLeft = A[i-1]
			} else {
				maxLeft = max(A[i-1], B[j-1])
			}
			if (m+n)&0x1 == 1 {
				// 总数为奇数
				return float64(maxLeft)
			}
			minRight := 0
			if i == m {
				minRight = B[j]
			} else if j == n {
				minRight = A[i]
			} else {
				minRight = min(B[j], A[i])
			}
			out = float64(maxLeft+minRight) * 0.5
			return
		}
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
