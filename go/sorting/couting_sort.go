package sorting

func CountingSort(a []int) {
	if len(a) < 2 {
		return
	}
	var (
		min = a[0]
		max = a[0]
	)
	for _, x := range a {
		if x > max {
			max = x
		} else if x < min {
			min = x
		}
	}
	b := make([]int, max - min + 1)
	for _, x := range a {
		b[x - min]++
	}
	var i int
	for x, c := range b {
		for j := 0; j < c; j++ {
			a[i] = min + x
			i++
		}
	}
}
