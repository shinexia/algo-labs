package sorting

func QuickSort(a []int) {
	quickSort(a, 0, len(a)-1)
}

func quickSort(data []int, start, end int) {
	if start >= end {
		return
	}
	if start+1 == end {
		if data[start] > data[end] {
			swap(data, start, end)
		}
		return
	}
	mid := partition(data, start, end)
	quickSort(data, start, mid-1)
	quickSort(data, mid+1, end)
}

func partition(data []int, start, end int) int {
	var (
		m     = int(uint(start+end) >> 1)
		pivot = data[m]
		i     = start + 1
		j     = end
	)
	swap(data, start, m)
	for {
		for ; i < j && data[j] >= pivot; j-- { // data[j] < pivot
		}
		for ; i < j && data[i] < pivot; i++ { // data[i] >= pivot
		}
		if i >= j {
			break
		}
		// data[i] < pivot, data[j] >= pivot
		swap(data, i, j)
		i++
		j--
	}
	if data[j] >= pivot {
		j--
		if j == start {
			return start
		}
	}
	swap(data, start, j)
	return j
}
