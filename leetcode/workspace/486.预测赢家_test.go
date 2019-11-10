package workspace

import "testing"

func TestPredictTheWinner(t *testing.T) {
    cases := []struct {
        nums []int
        expect bool
    } {
        {[]int{1, 5, 2},  false},
        {[]int{1, 5, 233, 7},  true},
    }
    for _, c := range cases {
        out := PredictTheWinner(c.nums)
        if out != c.expect {
            t.Errorf("nums: %v, out: %v, expect: %v", c.nums, out, c.expect)
        }
    }
}
