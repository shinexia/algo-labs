package skiplist

import (
	"testing"
	"log"
	"fmt"
)

func TestNew(t *testing.T) {
	s := New()
	if a := s.Find(nil); a != nil {
		t.Error("s[nil]=" + fmt.Sprint(a) + " should eq nil")
	}

	s.Put(Int(0), 2)
	log.Println(s.String())
	if a := s.Find(Int(0)); a != 2 {
		t.Error("s[0]=" + fmt.Sprint(a) + " should eq 2")
	}

	s.Put(nil, 3)
	log.Println(s.String())
	if a := s.Find(nil); a != 3 {
		t.Error("s[nil]=" + fmt.Sprint(a) + " should eq 3")
	}

	s.Put(Int(0), 4)
	log.Println(s.String())
	if a := s.Find(Int(0)); a != 4 {
		t.Error("s[0]=" + fmt.Sprint(a) + " should eq 4")
	}

	if a := s.Find(Int(1)); a != nil {
		t.Error("s[1]=" + fmt.Sprint(a) + " should eq nil")
	}

	s.Remove(Int(0))
	log.Println(s.String())
	if a := s.Find(Int(0)); a != nil {
		t.Error("s[0]=" + fmt.Sprint(a) + " should eq nil")
	}

	s.Remove(nil)
	log.Println(s.String())
	if a := s.Find(Int(0)); a != nil {
		t.Error("s[nil]=" + fmt.Sprint(a) + " should eq nil")
	}
}

func TestInt_Compare(t *testing.T) {
	var b *Int = nil
	log.Println(doCompare(nil, b))
}

func doCompare(a, b Key) int {
	return a.Compare(b)
}
