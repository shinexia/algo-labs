package sorting

func BucketSort(a []int) {
	N := len(a)
	if N < 2 {
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
	step := 10
	bucketNum := max/step - min/step + 1
	buck := make([][]int, bucketNum)

	// create bucket
	for i := 0; i < bucketNum; i++ {
		buck[i] = make([]int, 0, bucketNum)
	}

	// push into the bucket
	for i, x := range a {
		index := indexFor(a[i], min, step)
		buck[index] = append(buck[index], x)
	}

	var index int
	for i := 0; i < bucketNum; i++ {
		bucket := buck[i]
		InsertSort(bucket)
		for _, k := range bucket {
			a[index] = k
			index++
		}
	}
}

func indexFor(a, min, step int) int {
	return (a - min) / step
}
