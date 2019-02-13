#!/bin/bash

dest_dir=$(pwd)/build

cd third_party/gtest/googletest

mkdir mybuild

cd mybuild

cmake -DBUILD_SHARED_LIBS=ON ..

make

mkdir -p ${dest_dir}/include ${dest_dir}/lib

cp -r ../include/gtest ${dest_dir}/include/

cp lib/lib* ${dest_dir}/lib

cd ../

rm -fr mybuild
