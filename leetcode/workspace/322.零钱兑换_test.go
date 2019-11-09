package workspace

import "testing"

func TestCoinsChange(t *testing.T) {
	cases := []struct {
		coins  []int
		amount int
		expect int
	}{
		{[]int{1}, 1, 1},
		{[]int{1}, 0, 0},
		{[]int{1, 2, 5, 10, 11}, 20, 2},
		{[]int{2, 5, 10, 1}, 27, 4},
		{[]int{406, 435, 260, 178, 55}, 2924, 9},
		{[]int{186, 419, 83, 408}, 6249, 20},
		{[]int{156, 265, 40, 280}, 9109, 35},
		{[]int{65, 451, 124, 70, 480, 441}, 4129, 10},
	}
	for _, c := range cases {
		out := coinChange(c.coins, c.amount)
		if out != c.expect {
			t.Errorf("coins: %v, amount: %v, out: %v, expect: %v", c.coins, c.amount, out, c.expect)
		}
	}
}
