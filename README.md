
[![Build Status](https://travis-ci.com/NicolasKeita/R-type-video-game.svg?token=yCU9eZUj8esevSHWuiuJ&branch=master)](https://travis-ci.com/NicolasKeita/R-type-video-game)

# R-Type
R-Type is a "shoot them up" 2D video game.

We added multiplayer to the game.

We created the game with the SFML library.

## Usage

You will find executables in the bin folder. Run the server then the client (let the server open).

You can config the network by adding parameters, e.g :
 1) ```$ ./r-type_server 42424```
 
 2) ```$ ./r-type_client 0.0.0.0 42424```
 
## Compilation

Want to compile yourself from source code ?

Linux :

Prerequisites :
Conan (to install Boost.asio) : https://conan.io

Cmake version 3.12.4 minimun

Package : openal, g++, libtool (linux only. Fedora : ```# dnf install openal g++ libtool``` ; Ubuntu : ```# apt-get install -y libopenal-dev libalut-dev && apt-get -y build-dep libsfml```)
1) ``` $ bash build.bash```

Windows :

Prerequisites :
Visual Studio (with the C++ addons)
1) ?
2) ?
