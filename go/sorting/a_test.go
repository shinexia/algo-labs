package sorting

import (
	"testing"
)

var cases = []struct {
	a      []int
	expect []int
}{
	{a: nil, expect: nil},
	{a: []int{}, expect: []int{}},
	{a: []int{1}, expect: []int{1}},
	{a: []int{1, 2}, expect: []int{1, 2}},
	{a: []int{2, 1, 3}, expect: []int{1, 2, 3}},
	//{a: []int{2, -1, -3}, expect: []int{-3, -1, 2}},
	{a: []int{3, 5, 4}, expect: []int{3, 4, 5}},
	{a: []int{3, 5, 4, 3}, expect: []int{3, 3, 4, 5}},
	{a: []int{5, 3, 8, 6, 4}, expect: []int{3, 4, 5, 6, 8}},
	{a: []int{6, 1, 2, 7, 9, 3, 4, 5, 10, 8}, expect: []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}},
	{a: []int{6, 5, 3, 1, 8, 7, 2, 4}, expect: []int{1, 2, 3, 4, 5, 6, 7, 8}},
	{a: []int{13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10}, expect: []int{10, 13, 14, 23, 25, 25, 27, 33, 39, 45, 59, 65, 73, 82, 94, 94}},
	{a: []int{3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6}, expect: []int{0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9}},
	{a: []int{16, 4, 10, 14, 7, 9, 3, 2, 8, 1}, expect: []int{1, 2, 3, 4, 7, 8, 9, 10, 14, 16}},
}

type sorter func([]int)

func testSorting(fn sorter, t *testing.T) {
	for _, c := range cases {
		out := clone(c.a)
		if fn(out); !isRight(out, c.expect) {
			t.Errorf("a=%v, out=%#v, expect=%#v", c.a, out, c.expect)
		}
	}
}

func benchmarkSorting(fn sorter, b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, c := range cases {
			fn(c.a)
		}
	}
}

func clone(a []int) []int {
	b := make([]int, len(a))
	for i, n := range a {
		b[i] = n
	}
	return b
}

func isRight(a, b []int) bool {
	if len(a) == 0 {
		return len(b) == 0
	}
	for i, n := range a {
		if i >= len(b) || n != b[i] {
			return false
		}
		if i > 1 && a[i] < a[i-1] {
			return false
		}
	}
	return true
}

func TestSelectSort(t *testing.T) {
	testSorting(SelectSort, t)
}

func TestQuickSort(t *testing.T) {
	testSorting(QuickSort, t)
}

func TestInsertSort(t *testing.T) {
	testSorting(InsertSort, t)
}

func TestBubbleSort(t *testing.T) {
	testSorting(BubbleSort, t)
}

func TestShellSort(t *testing.T) {
	testSorting(ShellSort, t)
}

func TestMergeSort(t *testing.T) {
	testSorting(MergeSort, t)
}

func TestHeapSort(t *testing.T) {
	testSorting(HeapSort, t)
}

func TestCountingSort(t *testing.T) {
	testSorting(CountingSort, t)
}

func TestBucketSort(t *testing.T) {
	testSorting(BucketSort, t)
}

func TestRadixSort(t *testing.T) {
	testSorting(RadixSort, t)
}

func BenchmarkSelectSort(b *testing.B) {
	benchmarkSorting(SelectSort, b)
}

func BenchmarkQuickSort(b *testing.B) {
	benchmarkSorting(QuickSort, b)
}

func BenchmarkInsertSort(b *testing.B) {
	benchmarkSorting(InsertSort, b)
}

func BenchmarkBubbleSort(b *testing.B) {
	benchmarkSorting(BubbleSort, b)
}

func BenchmarkShellSort(b *testing.B) {
	benchmarkSorting(ShellSort, b)
}

func BenchmarkMergeSort(b *testing.B) {
	benchmarkSorting(MergeSort, b)
}

func BenchmarkHeapSort(b *testing.B) {
	benchmarkSorting(HeapSort, b)
}

func BenchmarkCountingSort(b *testing.B) {
	benchmarkSorting(CountingSort, b)
}

func BenchmarkBucketSort(b *testing.B) {
	benchmarkSorting(BucketSort, b)
}

func BenchmarkRadixSort(b *testing.B) {
	benchmarkSorting(RadixSort, b)
}
