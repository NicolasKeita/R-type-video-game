
[![Build Status](https://travis-ci.com/NicolasKeita/R-type-video-game.svg?token=yCU9eZUj8esevSHWuiuJ&branch=master)](https://travis-ci.com/NicolasKeita/R-type-video-game)

# R-Type
R-Type is a "shoot them up" 2D video game.

We added multiplayer to the game.

We created the game with the SFML library.

## Usage

Want to play ? You will find executables in the bin folder. Run the server then the client (let the server open).

You can configurate the network by adding parameters, e.g :
 1) ```$ ./r-type_server 42424```
 
 2) ```$ ./r-type_client 0.0.0.0 42424```
 

## Linux compilation :

#### Install prerequisites :

Conan (to install Boost.asio) : https://conan.io

Cmake version 3.12.4 minimun

SFML dependancies : https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php

Here is how to quickly install them on Fedora and Ubuntu :

- On Fedora : ```# ./script/install_requirements_to_build_SFML_on_fedora.sh```

- On Ubuntu : ```# apt-get install -y libopenal-dev libalut-dev && apt-get -y build-dep libsfml```

#### Then compile executables with my script
``` $ ./build_executables_linux.sh```

## Windows compilation :

Prerequisites :
Visual Studio (with the C++ addons)
1) ?
2) ?
