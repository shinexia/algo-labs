package workspace

/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 */

// @lc code=start

import (
	"sort"
)

func coinChange(coins []int, amount int) int {
	if amount <= 0 {
		return amount
	}
	sort.Ints(coins)
	ctx := &context{
		min: -1, // amount+1可能会溢出
	}
	coinChangeHelper(coins, amount, 0, len(coins)-1, ctx)
	return ctx.min
}

type context struct {
	min int
}

func coinChangeHelper(coins []int, amount int, depth int, idx int, ctx *context) {
	if idx < 0 {
		return
	}
	coin := coins[idx]
	count := amount / coin
	if depth+count >= ctx.min && ctx.min > 0 {
		return
	}
	if amount%coin == 0 {
		ret := depth + count
		if ret < ctx.min || ctx.min == -1 {
			ctx.min = ret
		}
		return
	}
	idx--
	for ; count >= 0; count-- {
		coinChangeHelper(coins, amount-count*coin, depth+count, idx, ctx)
	}
	return
}

// @lc code=end
