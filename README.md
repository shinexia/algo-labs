# algorithm-labs

algorithm labs

## Go Tests Coverage

```bash
go test -cover
```

or

```bash
go tool cover -html=cover.out
```

## C/C++

on Mac, install `gtest`

```bash
git clone https://github.com/google/googletest.git
cd googletest/googletest
cmake cmake -DBUILD_SHARED_LIBS=ON .
cp -a include/gtest /usr/local/include
cp -a libgtest.dylib libgtest_main.dylib /usr/local/lib
```

build `mylib`

```bash
cd cpp
make
```
