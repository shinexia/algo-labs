package sorting

func ShellSort(a []int) {
	N := len(a)
	if N < 2 {
		return
	}
	var gap = 1
	for gap < N/3 {
		gap = 3*gap + 1 // <O(n^(3/2)) by Knuth,1973>: 1, 4, 13, 40, 121, ...
	}
	for gap > 0 {
		for i := gap; i < N; i++ {
			tmp := a[i]
			var j int
			for j = i - gap; j >= 0 && a[j] > tmp; j -= gap {
				a[j+gap] = a[j]
			}
			a[j+gap] = tmp
		}
		gap /= 3
	}
}
