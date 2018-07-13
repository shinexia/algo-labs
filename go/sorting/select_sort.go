package sorting

func SelectSort(a []int) {
	for i, n := range a {
		var min = n
		var mi = i
		for j := i + 1; j < len(a); j++ {
			if a[j] < min {
				min = a[j]
				mi = j
			}
		}
		if mi != i {
			swap(a, i, mi)
		}
	}
}
