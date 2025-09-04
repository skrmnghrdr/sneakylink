#!/bin/bash

# Compile the program

if gcc -Wall -Werror src/part_1.c -o part_1; then
    echo "PE Part 1 Passed
else
    echo "PE Part 1 Failed"
fi

# Clean 

rm -rf part_1
