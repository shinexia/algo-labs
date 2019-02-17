package _848_shifting_letters

// https://leetcode.com/contest/weekly-contest-88/problems/shifting-letters/

const runeA = 'a'
const runeZ = 'z'
const base = runeZ - runeA + 1
const runeZA = - runeZ - 1 + runeA

func shift(c byte, n int) (out byte) {
	n = int(c) + n % base
	if n  > runeZ {
		n += runeZA
	}
	return byte(n)
}

func shiftingLetters(S string, shifts []int) string {
	L := len(shifts)
	out := make([]byte, L)
	sum := 0
	for i := L - 1; i >= 0; i-- {
		sum += shifts[i]
		out[i] = shift(S[i], sum)
	}
	return string(append(out, S[L:]...))
}
