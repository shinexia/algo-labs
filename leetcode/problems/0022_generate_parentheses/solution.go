package _022_generate_parentheses

// https://leetcode.com/problems/generate-parentheses/

func generateParenthesis(n int) []string {
	if n == 0 {
		return []string{}
	}
	buf := make([]byte, n*2)
	return backtracing(nil, buf, 0, 0, n)
}

func backtracing(answers []string, s []byte, open, close, max int) []string {
	if open+close == max*2 {
		return append(answers, string(s))
	}
	if open < max {
		s[open+close] = '('
		answers = backtracing(answers, s, open+1, close, max)
	}
	if close < open {
		s[open+close] = ')'
		answers = backtracing(answers, s, open, close+1, max)
	}
	return answers
}
