# algolabs

Most used: go and c++

Developed on Ubuntu 18.04 x64, build on MacOSx could fail.

## Prerequisites

```bash
git submodule update --init
sudo apt install valgrind
```

## Tips

### C++ MemCheck

```bash
mkdir build && cd build
cmake -G Ninja ..
ninja
ninja ExperimentalMemCheck
```

Ninja中的`N`一定要大写, vscode -> cmake generator 配置时也要注意首字母大写

或者在vscode cmake outline中右键`ExperimentalMemCheck`执行。

`Ninja` 失败的话，可以用Makefile

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
make test
ctest -R ExperimentalMemCheck
```

### Go Tests Coverage

```bash
go test -cover
# or
go tool cover -html=cover.out
```

## Editor

VS Code with CMAKE


## LICENSE

[MIT License](LICENSE)
