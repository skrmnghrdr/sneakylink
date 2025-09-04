#!/bin/bash


# Part 1

if ! gcc -Wall -Werror src/compare_string.c -o compare_string; then
    echo "Part 1 Compilation Failed."
else
    echo "Part 1 Compiled."
fi

if ! ./compare_string pe_resources/compare_input.txt; then
    echo "Part 1 Test Failed."
    exit 0
else
    echo "Part 1 Test Passed!"
fi

rm -rf compare_string


# Part 2

if ! gcc -Wall -Werror src/concat_string.c -o concat_string; then
    echo "Part 2 Compilation Failed."
else
    echo "Part 2 Compiled."
fi

if ! ./concat_string pe_resources/concat_input.txt; then
    echo "Part 2 Test Failed."
    exit 0
else
    echo "Part 2 Test Passed!"
fi

rm -rf concat_string

# Part 3

if ! gcc -Wall -Werror src/search_string.c -o search_string; then
    echo "Part 3 Compilation Failed."
else
    echo "Part 3 Compiled."
fi

if ! ./search_string pe_resources/search_input.txt; then
    echo "Part 3 Test Failed."
    exit 0
else
    echo "Part 3 Test Passed!"
fi

rm -rf search_string

# Part 4

if ! gcc -Wall -Werror src/tokenize_string.c -o tokenize_string; then
    echo "Part 4 Compilation Failed."
else
    echo "Part 4 Compiled."
fi

if ! ./tokenize_string pe_resources/tokenize_input.txt; then
    echo "Part 4 Test Failed."
    exit 0
else
    echo "Part 4 Test Passed!"
fi

rm -rf tokenize_string