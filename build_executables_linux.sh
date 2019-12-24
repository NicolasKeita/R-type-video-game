#!/usr/bin/env sh

mkdir -p ./build/
cd ./build/ || exit
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
#change 9.2 to your gcc version (gcc --version)
conan install ../ --build=missing -s compiler=gcc -s compiler.version=9.2 -s compiler.libcxx=libstdc++11 -s build_type=Release -g virtualenv
cmake -DCMAKE_BUILD_TYPE=Release ../
cmake --build ./ -j "$(nproc --all)"
cp -rf ../bin/Linux/assets ./bin
echo -e "\n\nExecutables are located in build/bin/\n"
echo "If shared libraries are not found, use the script: activate.sh in build/  Usage : $ source activate.sh"

#windows 10
#conan install ../ --build=missing -s compiler="Visual Studio" -s compiler.version=16 -s compiler.cppstd=14 -s build_type=Release -g virtualenv
