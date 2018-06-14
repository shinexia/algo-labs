package _003_length_of_longest_substring

import (
	"testing"
	"fmt"
	"strings"
)

func TestStringIndex(t *testing.T) {
	s := "hello"

	idx := strings.IndexRune(s, rune('o'))
	fmt.Println(s[idx+1:])

	fmt.Println(strings.IndexRune(s, rune('z')))
}

func TestLongest(t *testing.T) {
	if LengthOfLongestSubstring("abcabcbb") != 3 {
		t.Error()
	}
	if LengthOfLongestSubstring("bbbbb") != 1 {
		t.Error()
	}
	if LengthOfLongestSubstring("pwwkew") != 3 {
		t.Error()
	}
	if LengthOfLongestSubstring("c") != 1 {
		t.Error()
	}
}
