package kaler

func solution(n int) int {
	c := newSolver(n)
	return c.resolve()
}

type solver struct {
	n  int
	dp [][]int
}

func newSolver(n int) *solver {
	c := &solver{
		n:  n,
		dp: nil,
	}
	c.dp = make([][]int, n-1)
	for i := 0; i < n-1; i++ {
		c.dp[i] = make([]int, n)
	}
	return c
}

func (c *solver) resolve() int {
	return c.iter(c.n, c.n)
}

func (c *solver) iter(n int, sum int) int {
	if n == 1 || sum == 0 {
		return 1
	}
	if n == 2 {
		return sum + 1
	}
	r := c.dp[n-2][sum-1]
	if r > 0 {
		return r
	}
	for i := 0; i <= sum; i++ {
		r += c.iter(n-1, sum-i)
	}
	c.dp[n-2][sum-1] = r
	return r
}
