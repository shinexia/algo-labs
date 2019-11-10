package workspace

/*
 * @lc app=leetcode.cn id=486 lang=golang
 *
 * [486] 预测赢家
 */

// @lc code=start

type Ret struct {
	a int
	b int
}

func PredictTheWinner(nums []int) bool {
	dp := make(map[int]*Ret, len(nums))
    a, b := PredictTheWinner0(nums, dp, 0, len(nums)-1)
    return a >= b
}

func PredictTheWinner0(nums []int, dp map[int]*Ret, start, end int) (ra int, rb int) {
	key := start * 200 + end
	ret, ok := dp[key]
	if ok {
		return ret.a, ret.b
	}
	defer func() {
		ret = &Ret{
			a: ra,
			b: rb,
		}
		dp[key] = ret
	}()
    switch {
    case start > end:
        return 0, 0
    case start == end:
        return nums[start], 0
    case start == end-1:
        if nums[start] > nums[end] {
            return nums[start], nums[end]
        }
        return nums[end], nums[start]
    }
    // a = nums[start]
    b1, a1 := PredictTheWinner0(nums, dp, start+1, end)
    a1 += nums[start]
    // a = nums[end]
    b2, a2 := PredictTheWinner0(nums, dp, start, end-1)
    a2 += nums[end]
    //
    if a1 > a2 {
        return a1, b1
    }
    return a2, b2
}

// @lc code=end

