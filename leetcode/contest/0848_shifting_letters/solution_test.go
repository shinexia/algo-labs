package _848_shifting_letters

import "testing"

func TestShiftingLetters(t *testing.T) {
	tests := []struct{
		s string
		shifts []int
		expect string
	} {
		{s: "", shifts: nil, expect: ""},
		{s: "abc", shifts: nil, expect: "abc"},
		{s: "abc", shifts: []int{1, 1, 1}, expect: "ddd"},
		{s: "abc", shifts: []int{3, 5, 9}, expect: "rpl"},
		{s: "xyz", shifts: []int{1, 1, 1}, expect: "aaa"},
	}
	for _, test := range tests {
		if out := shiftingLetters(test.s, test.shifts); out != test.expect {
			t.Errorf("s=%s, shifts=%v, out=%s, expect=%s", test.s, test.shifts, out, test.expect)
		}
	}
}
