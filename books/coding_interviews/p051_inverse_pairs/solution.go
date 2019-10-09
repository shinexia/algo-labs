package p051_inverse_pairs

func InversePairs(data []int) int {
	if len(data) <= 1 {
		return 0
	}
	temp := make([]int, len(data))
	copy(temp, data)
	return partial(data, temp, 0, len(data)-1)
}

func partial(a []int, b []int, start, end int) int {
	if start == end {
		return 0
	}
	// copy b to a
	mid := int(uint(start+end) >> 1)
	left := partial(b, a, start, mid)
	right := partial(b, a, mid+1, end)
	// then copy a to b
	var (
		i     = start
		j     = mid + 1
		count = left + right
	)
	for k := start; k <= end; k++ {
		if i <= mid && j <= end && b[i] > b[j] {
			a[k] = b[j]
			count += mid - i + 1
			j++
		} else if i <= mid {
			a[k] = b[i]
			i++
		} else {
			a[k] = b[j]
			j++
		}
	}
	return count
}
