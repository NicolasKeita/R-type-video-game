mkdir build
cd build
conan install ../ --build=missing -s compiler="Visual Studio" -s compiler.version=16 -s compiler.cppstd=14 -s build_type=Release -g virtualenv
cmake -DCMAKE_BUILD_TYPE=Release ../
cmake --build ./
cp -r ../bin/Linux/assets ./bin
echo ""
echo "Compilation successfully completed !"
echo " ---- Executables are located in build/bin/"
cd ../
