package fibonacci

// 尾递归实现
func fibonacci(n int) int {
	if n < 1 {
		return 0
	}
	return recursive(0, 1, 1, n)
}

func recursive(a1, a2, n, max int) int {
	if n == max {
		return a2
	}
	return recursive(a2, a1+a2, n+1, max)
}

// 循环实现
func fib(n int) int {
	if n < 1 {
		return 0
	}
	a, b := 0, 1
	for i := 1; i < n; i++ {
		b, a = a+b, b
	}
	return b
}
