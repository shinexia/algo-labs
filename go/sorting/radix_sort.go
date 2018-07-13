package sorting

import "fmt"

func RadixSort(a []int) {
	if len(a) < 2 {
		return
	}
	const BASE = 10
	var (
		n     = len(a)
		d     = maxbit(a, BASE)
		tmp   = make([]int, n)
		count = [BASE]int{} //计数器
		radix = 1
	)
	for i := 0; i < d; i++ { //进行d次排序
		for j := 0; j < BASE; j ++ {
			count[j] = 0 //每次分配前清空计数器
		}
		for j := 0; j < n; j++ {
			k := (a[j] / radix) % BASE //统计每个桶中的记录数
			count[k]++
		}
		fmt.Println("before", count)
		for j := 1; j < BASE; j++ {
			count[j] += count[j-1] //将tmp中的位置依次分配给每个桶
		}
		fmt.Println("after", count)
		fmt.Println(a, tmp)
		for j := n - 1; j >= 0; j-- { //将所有桶中记录依次收集到tmp中
			k := (a[j] / radix) % BASE
			tmp[count[k]-1] = a[j]
			count[k]--
		}
		for j := 0; j < n; j++ { //将临时数组的内容复制到a中
			a[j] = tmp[j]
		}
		radix *= BASE
	}
}

func maxbit(a []int, base int) int { //辅助函数，求数据的最大位数
	var max = a[0]
	for _, x := range a {
		if x > max {
			max = x
		}
	}
	d := 1
	for max >= base {
		//p *= 10; // Maybe overflow
		max /= base
		d++
	}
	return d
}
