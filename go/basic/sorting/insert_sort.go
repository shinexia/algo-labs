package sorting

func InsertSort(a []int) {
	for i := 1; i<len(a); i++ {
		var j = i
		target := a[i]
		for j > 0 && a[j - 1] > target {
			a[j] = a[j - 1]
			j--
		}
		a[j] = target
	}
}
