#!/bin/bash

g++ main.cpp -o hsv_threshold `pkg-config --libs opencv` `pkg-config --cflags opencv`

