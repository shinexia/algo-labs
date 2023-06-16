package sorting

func HeapSort(a []int) {
	N := len(a)
	for i := N>>1 - 1; i >= 0; i-- {
		maxHeapify(a, i, N-1)
	}
	for i := N - 1; i > 0; i-- {
		swap(a, 0, i)
		maxHeapify(a, 0, i-1)
	}
}

func maxHeapify(a []int, start, end int) {
	var (
		dad = start
		son = dad<<1 + 1
	)
	for son <= end {
		if son+1 <= end && a[son] < a[son+1] {
			son++
		}
		if a[dad] > a[son] {
			return
		} else {
			swap(a, dad, son)
			dad = son
			son = dad<<1 + 1
		}
	}
}
