package sorting


func MergeSort(A []int) {
	a := A
	N := len(a)
	b := make([]int, N)
	var seg, start int
	for seg = 1; seg < N; seg += seg {
		for start = 0; start < N; start += seg + seg {
			var (
				low = start
				mid = min(start + seg, N)
				high = min(start + seg + seg, N)
				k = low
				start1 = low
				end1= mid
				start2 = mid
				end2 = high
			)
			for start1 < end1 && start2 < end2 {
				if a[start1] < a[start2] {
					b[k] = a[start1]
					k++
					start1++
				} else {
					b[k] = a[start2]
					k++
					start2++
				}
			}
			for start1 < end1 {
				b[k] = a[start1]
				k++
				start1++
			}
			for start2 < end2 {
				b[k] = a[start2]
				k++
				start2++
			}
		}
		a, b = b, a
	}
	if &a != &A {
		// 说明 b == A
		for i := 0; i < N; i++ {
			b[i] = a[i]
		}
	}
}
