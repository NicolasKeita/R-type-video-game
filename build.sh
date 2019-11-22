#!/bin/sh

mkdir -p ./build/
cd ./build/
conan install ../ --build=missing
cmake ../
cmake --build ./ && cp bin/R_type_video_game ../
cd ../
