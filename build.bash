#!/usr/bin/env bash

mkdir -p ./build/
cd ./build/ || exit
conan install ../ --build=missing -s compiler.libcxx=libstdc++11 -s build_type=Debug -g virtualenv
source activate.sh
cmake ../
cmake --build ./ -j "$(nproc --all)"
cp bin/r-type_client ../
cd ../
