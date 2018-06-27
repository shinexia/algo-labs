package search

const (
	NotFound = -1
)

func BinarySearch(A []int, x int) int {
	var (
		low  = 0
		high = len(A) - 1
		mid  int
	)
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
