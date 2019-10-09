package p050_2_stream_first_char

import "testing"

func TestCharReader(t *testing.T) {
	cases := []struct {
		in     string
		expect byte
	}{
		{"", 0},
		{"g", 'g'},
		{"z", 'z'},
		{"gg", 0},
		{"gggggg", 0},
		{"go", 'g'},
		{"google", 'l'},
	}
	for _, c := range cases {
		r := New()
		for _, b := range []byte(c.in) {
			r.Insert(b)
		}
		out := r.Get()
		if out != c.expect {
			t.Errorf("in: %v, out: %v, expect: %v", c.in, string(out), string(c.expect))
		}
	}
}
