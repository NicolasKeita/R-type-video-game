
[![Build Status](https://travis-ci.com/NicolasKeita/R-type-video-game.svg?token=yCU9eZUj8esevSHWuiuJ&branch=master)](https://travis-ci.com/NicolasKeita/R-type-video-game)

# R-Type
R-Type is a "shoot them up" 2D video game.

We added multiplayer to the game.

We created the game with the SFML library.

## Prerequisites

Conan (to install Boost.asio) : https://conan.io

Cmake version 3.12.4 minimun

Package : openal-soft (linux only. Fedora : ```$ dnf install openal``` ; Ubuntu : ```$ apt-get install -y libopenal-dev libalut-dev && apt-get -y build-dep libsfml```)

## Usage

Linux :

``` $ bash build.bash```

 ```$ ./r-type_server```
 
 ```$ ./r-type_client 0.0.0.0 42424``` (if the server doesn't run on your computer, change 0.0.0.0 to the IP address of your server machine)
 
 TODO : put the server address in arg
 

Windows :

``` ask my team ```
