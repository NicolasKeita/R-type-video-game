#!/usr/bin/env sh

mkdir -p ./build/
cd ./build/ || exit
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
conan install ../ --build=missing -s compiler=gcc -s compiler.version="$(gcc -v 2>&1 | tail -1 | awk '{print $3}' | cut -d "." --fields=1-2)" -s compiler.libcxx=libstdc++11 -s build_type=Release -g virtualenv
cmake -DCMAKE_BUILD_TYPE=Release ../
cmake --build ./ -j "$(nproc --all)"
cp -rf ../bin/Linux/assets ./bin
echo -e "\n\nExecutables are located in build/bin/\n"
echo "If shared libraries are not automatically found, use the script: activate.sh in build/  Usage : $ source activate.sh"

# If Conan is indefinitely locked, run the following command :
# conan remove "*" -f && conan --remove locks && rm -rf ~/.conan/data/*
