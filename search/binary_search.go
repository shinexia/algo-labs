package search

func BinarySearch(arr []int, key int) int {
	return binarySearch0(arr, 0, len(arr), key)
}

func binarySearch0(arr []int, low, high, key int) int {
	mid := low + (high-low)/2
	if mid >= len(arr) {
		return -1
	}
	mval := arr[mid]
	if mval > key {
		return binarySearch0(arr, low, mid-1, key)
	} else if mval < key {
		return binarySearch0(arr, mid+1, high, key)
	}
	return mid
}
