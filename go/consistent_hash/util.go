package consistent_hash

import (
	"unsafe"
)

func unsafeStrToBytes(s string) []byte {
	return *(*[]byte)(unsafe.Pointer(&s))
}

func unsafeBytesToStr(b []byte) string {
	return *(*string)(unsafe.Pointer(&b))
}
