#!/bin/sh

cmake -S . -B build
cmake --build build && cp build/R_type_video_game ./
