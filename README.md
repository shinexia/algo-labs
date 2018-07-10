# algorithm-labs

Most used programming languages: go, c, c++, haskell, racket

## Prerequisites

### install gtest

on Mac

```bash
git clone https://github.com/google/googletest.git
cd googletest/googletest
cmake cmake -DBUILD_SHARED_LIBS=ON .
cp -a include/gtest /usr/local/include
cp -a libgtest.dylib libgtest_main.dylib /usr/local/lib
```

### build mylib@cpp

```bash
cd cpp
make
```

## Tips

### Go Tests Coverage

```bash
go test -cover
```

or

```bash
go tool cover -html=cover.out
```
