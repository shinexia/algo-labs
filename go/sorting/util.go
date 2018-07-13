package sorting

func swap(a []int, i, j int) {
	a[i], a[j] = a[j], a[i]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
