#!/bin/bash

 g++ main.cpp -o live_view `pkg-config --libs opencv` `pkg-config --cflags opencv`

