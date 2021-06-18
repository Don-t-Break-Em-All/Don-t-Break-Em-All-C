#!/bin/bash


gcc -Wall $(find . -name "*.c") -Iinclude -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Ofast -o dba