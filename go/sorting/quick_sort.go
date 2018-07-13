package sorting

func QuickSort(a []int) {
	quickSort(a, 0, len(a) - 1)
}

func quickSort(a []int, start, end int) {
	if start >= end {
		return
	}
	var (
		mid = a[start]
		i   = start // 最终i会被移动到a[start]的正确位置，但a[start]可能已经在正确的位置了，所以此处不能取start+1
		j   = end
	)
	for i < j {
		for i < j && a[j] >= mid {
			j--
		}
		for i < j && a[i] <= mid { // 这里必须取等，因为i=start时，a[i] == mid成立，导致a[i]被交换
			i++
		}
		if i < j {
			swap(a, i, j)
		}
	}
	if a[start] > a[i] {
		swap(a, start, i)
	}
	quickSort(a, start, i - 1)
	quickSort(a, i + 1, end)
}
