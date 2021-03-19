package sorting


func QuickSort(a []int) {
	quickSort(a, 0, len(a)-1)
}

func quickSort(data []int, start, end int) {
	if start+1 >= end {
		if start + 1 == end && data[start] > data[end] {
			swap(data, start, end)
		}
		return
	}
	mid := partition(data, start, end)
	quickSort(data, start, mid-1)
	quickSort(data, mid+1, end)
}

func partition(nums []int, start, end int) int {
	mid := int(uint(start + end) >> 1)
	nums[start], nums[mid] = nums[mid], nums[start]
	p := nums[start]
    i, j := start + 1, end
    for {
		for ;nums[i] < p && i < j; i++ {}
		for ;nums[j] >= p && i <= j; j-- {}
        if i >= j {
            break
        }
        nums[i], nums[j] = nums[j], nums[i]
        i++
        j--
    }
    if start < j {
        nums[start], nums[j] = nums[j], nums[start]
    }
    return j
}
