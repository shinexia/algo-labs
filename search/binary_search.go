package search

const (
	NotFound = -1
)

func BinarySearch(A []int, x int) int {
	var (
		N    = len(A)
		low  = 0
		high = N - 1
		mid  int
	)
	if N > 0 && (x < A[low] || x > A[high]) {
		return NotFound
	}
	for low <= high {
		mid = (low + high) / 2
		m := A[mid]
		if x > m {
			low = mid + 1
		} else if x < m {
			high = mid - 1
		} else {
			// found
			return mid
		}
	}
	return NotFound
}
