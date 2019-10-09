package p050_2_stream_first_char

type CharReader struct {
	board  []int
	seq    int
	offset int
}

func New() *CharReader {
	return &CharReader{
		board: make([]int, 256),
		seq:   0,
	}
}

func (r *CharReader) Insert(c byte) *CharReader {
	r.seq++
	curr := r.board[c]
	if curr == 0 {
		r.board[c] = r.seq
	} else if curr > 0 {
		r.board[c] = -1
	}
	return r
}

func (r *CharReader) Get() byte {
	var (
		c   = 0
		seq = 256
	)
	for i := 0; i < 256; i++ {
		s := r.board[i]
		if r.board[i] > 0 {
			if s < seq {
				c = i
				seq = s
			}
		}
	}
	return byte(c)
}
