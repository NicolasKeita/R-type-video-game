#!/usr/bin/env bash

mkdir -p ./build/
cd ./build/ || exit
conan install ../ --build=missing -s compiler=gcc -s compiler.version=5.1 -s compiler.libcxx=libstdc++11 -s build_type=Debug -g virtualenv
source activate.sh
cmake -DCMAKE_BUILD_TYPE=Release ../
cmake --build ./ -j "$(nproc --all)"
cp bin/r-type_client ../
cd ../


#windows 10
conan install ../ --build=missing -s compiler="Visual Studio" -s compiler.version=16 -s compiler.cppstd=14 -s build_type=Debug -g virtualenv
