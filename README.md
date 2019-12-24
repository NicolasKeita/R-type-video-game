
[![Build Status](https://travis-ci.com/NicolasKeita/R-type-video-game.svg?token=yCU9eZUj8esevSHWuiuJ&branch=master)](https://travis-ci.com/NicolasKeita/R-type-video-game)

# R-Type
R-Type is a "shoot them up" 2D video game.

I tried to reproduce the original game and add multiplayer to the game.

My R-Type game has been created using the SFML library.

This repo has not been created to show a beautiful game but to exhibit my skills about :
- Network programming
- understand the difference between UNIX and Windows
- UML class diagram
- understand, use, and design an API

## Usage

Want to play ? You will find executables in the bin folder. Run the server then the client (let the server open).

You can configurate the network by adding parameters, e.g :
 1) ```$ ./r-type_server 42424```
 
 2) ```$ ./r-type_client 0.0.0.0 42424```
 

## Linux compilation :

#### Prerequisites to install :

- Conan (to install Boost.asio) : https://conan.io
- Cmake version 3.12.4 minimun
- SFML dependancies : https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php

Here is how to quickly install SFML dependancies on Fedora and Ubuntu :

- On Fedora : ```# ./script/install_requirements_to_build_SFML_on_fedora.sh```
- On Ubuntu : ```# apt-get install -y libopenal-dev libalut-dev && apt-get -y build-dep libsfml```

#### Then compile executables with my script
``` $ ./build_executables_linux.sh```

## Windows compilation :

#### Prerequisites to install :
- Conan (to install Boost.asio) : https://conan.io
- Cmake version 3.12.4 minimun
- Visual Studio with their C++ addon (this step is just to download visual studio compiler)

#### Then compile executables with my script
- Run the script ```$ ./build_executables_windows_10.ps1```

You have to run this script in a powershell (WINDOWS_KEY + X). To run a powershell script, you have to authorize scripts with the following command : ```$ Set-ExecutionPolicy RemoteSigned``` (```$ Set-ExecutionPolicy Restricted``` to undo)
