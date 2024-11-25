#!/bin/bash

g++ -std=c++17 -Wall -Wextra -g -O0 -D LINUX -I headers -I/usr/include/GL main.cpp -o program.out -lglfw -lGLEW -lGL 
./program.out