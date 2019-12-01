#!/bin/bash

mkdir -p ./build/
cd ./build/ || exit
conan install ../ --build=missing -s compiler.libcxx=libstdc++11 -g virtualenv
source activate.sh
cmake ../
cmake --build ./ -j "$(nproc --all)" && cp bin/R_type_video_game ../
cd ../
