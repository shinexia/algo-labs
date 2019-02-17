package _006_zigzag_conversion

import "testing"

func TestConvert(t *testing.T)  {
	cases := []struct{
		s string
		rows int
		expect string
	} {
		{s: "PAYPALISHIRING", rows: 0, expect: "PAYPALISHIRING"},
		{s: "PAYPALISHIRING", rows: 1, expect: "PAYPALISHIRING"},
		{s: "PAYPALISHIRING", rows: 2, expect: "PYAIHRNAPLSIIG"},
		{s: "PAYPALISHIRING", rows: 3, expect: "PAHNAPLSIIGYIR"},
		{s: "PAYPALISHIRING", rows: 4, expect: "PINALSIGYAHRPI"},
		{s: "", rows: 2, expect: ""},
		{s: "P", rows: 2, expect: "P"},
		{s: "PA", rows: 2, expect: "PA"},
		{s: "PAY", rows: 2, expect: "PYA"},
	}
	for _, c := range cases {
		if out := convert(c.s, c.rows); out != c.expect {
			t.Errorf("s=%s, rows=%d, out=%s, expect=%s", c.s, c.rows, out, c.expect)
		}
	}
}
