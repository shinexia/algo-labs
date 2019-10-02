package p003

func duplicate(nums []int) int {
	N := len(nums)
	for i, n := range nums {
		if n == i {
			continue
		}
		if n >= N {
			return -1
		}
		if n == nums[n] {
			return n
		}
		nums[i], nums[n] = nums[n], n
	}
	return -1
}

func duplicate2(nums []int) int {
	N := len(nums)
	if N <= 1 {
		return -1
	}
	for _, n := range nums {
		if n >= N || n < 1 {
			return -1
		}
	}
	start, end := 1, len(nums)
	for start < end-1 {
		mid := (start + end) / 2
		if count(nums, start, mid) {
			end = mid
		} else {
			start = mid
		}
	}
	return start
}

func count(nums []int, start, end int) bool {
	total := 0
	for _, n := range nums {
		if n >= start && n < end {
			total++
		}
	}
	return total > (end - start)
}
