#!/bin/bash

dest_dir=$(pwd)/build

cd third_party/myutil

make

mkdir -p ${dest_dir}/include ${dest_dir}/lib

cp -r include/* ${dest_dir}/include/

cp lib/lib* ${dest_dir}/lib

make distclean
