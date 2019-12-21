
[![Build Status](https://travis-ci.com/NicolasKeita/R-type-video-game.svg?token=yCU9eZUj8esevSHWuiuJ&branch=master)](https://travis-ci.com/NicolasKeita/R-type-video-game)

# R-Type
R-Type is a "shoot them up" 2D video game.

We added multiplayer to the game.

We created the game with the SFML library.

## Prerequisites

Conan (to install Boost.asio) : https://conan.io

Cmake version 3.12.4 minimun

Package : openal, g++ libtool (linux only. Fedora : ```$ dnf install openal g++ libtool``` ; Ubuntu : ```$ apt-get install -y libopenal-dev libalut-dev && apt-get -y build-dep libsfml```)

## Usage

Linux :

1) ``` $ bash build.bash``` (to compile)

 2) ```$ ./r-type_server``` (to start the server)
 
 3) ```$ ./r-type_client 0.0.0.0 42424``` (to start the game)
 
 (You can run the server and the game on different machines. If you do so, change 0.0.0.0 to the IP address of your server machine)
 

Windows :

``` ask my team ```
