package lib

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strconv"
)

const (
	scannerBufSize = 100000000
)

func LoadLines(path string) ([][]byte, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer file.Close()
	reader := bufio.NewScanner(file)
	reader.Buffer(make([]byte, scannerBufSize), scannerBufSize)
	var lines [][]byte
	for reader.Scan() {
		lines = append(lines, reader.Bytes())
	}
	if err := reader.Err(); err != nil {
		return lines, err
	}
	return lines, nil
}

func ParseArray(s []byte) ([]int, error) {
	var arr []int
	return arr, json.Unmarshal(s, &arr)
}

func ParseArrays(s []byte) ([][]int, error) {
	var arr [][]int
	return arr, json.Unmarshal(s, &arr)
}

func ParseInt(s []byte) (int, error) {
	return strconv.Atoi(string(s))
}

func LoadNArrays(path string) (int, [][]int, error) {
	lines, err := LoadLines(path)
	if err != nil {
		return 0, nil, err
	}
	if len(lines) != 2 {
		return 0, nil, fmt.Errorf("invalid lines num: %d, %v", len(lines), lines)
	}
	N, err := ParseInt(lines[0])
	if err != nil {
		return 0, nil, err
	}
	arr, err := ParseArrays(lines[1])
	return N, arr, err
}
