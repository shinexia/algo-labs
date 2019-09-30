package _017_letter_combinations_of_a_phone_number

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

var digits2letters = []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	return backtracking("", digits, nil)
}

func backtracking(combination, nextDigits string, answers []string) []string {
	if len(nextDigits) == 0 {
		return append(answers, combination)
	}
	digit := nextDigits[0]
	left := nextDigits[1:]
	letters := digits2letters[digit-'0'-2]
	for i := 0; i < len(letters); i++ {
		let := letters[i : i+1]
		answers = backtracking(combination+let, left, answers)
	}
	return answers
}

func letterCombinationsV1(digits string) []string {
	n := len(digits)
	if n == 0 {
		return []string{}
	}
	var letters = make([]string, n)
	var total = 1
	var bases = make([]int, n)
	for i := n - 1; i >= 0; i-- {
		lets := digits2letters[(digits[i]-'0')-2]
		letters[i] = lets
		bases[i] = total
		total *= len(lets)
	}
	var answers = make([]string, total)
	for i := 0; i < total; i++ {
		buf := make([]byte, n)
		for j := 0; j < n; j++ {
			lets := letters[j]
			buf[j] = lets[i/bases[j]%len(lets)]
		}
		answers[i] = string(buf)
	}
	return answers
}
