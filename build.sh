#!/bin/bash

mkdir -p ./build/
cd ./build/
conan install ../ --build=missing -g virtualenv
source activate.sh
cmake ../
cmake --build ./ && cp bin/R_type_video_game ../
cd ../
