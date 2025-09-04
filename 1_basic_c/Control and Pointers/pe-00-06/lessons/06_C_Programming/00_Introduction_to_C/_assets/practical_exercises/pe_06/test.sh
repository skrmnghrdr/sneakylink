#!/bin/bash

if ! gcc src/find-min-max.c -o find_min_max; then
    echo "Part 16 compilation error"
    exit 0
fi

if ! ./find_min_max > part_16.txt; then
    echo "Part 16 Runtime Error"
    exit 0
fi

if ! diff -i -w part_16.txt pe_resources/find-min-max_out.txt; then
    echo "Part 16 Test Failed"
    exit 0
else
    echo "Part 16 Test Passed"
fi

rm -rf find_min_max part_16.txt

if ! gcc src/sum-arrays.c -o sum_arrays; then
    echo "Part 17 compilation error"
    exit 0
fi

if ! ./sum_arrays > part_17.txt; then
    echo "Part 17 Runtime Error"
    exit 0
fi

if ! diff -i -w part_17.txt pe_resources/sum-arrays_out.txt; then
    echo "Part 17 Test Failed"
    exit 0
else
    echo "Part 17 Test Passed"
fi

rm -rf sum_arrays part_17.txt

if ! gcc src/sum-arrays-pointer.c -o sum_arrays_pointer; then
    echo "Part 18 compilation error"
    exit 0
fi

if ! ./sum_arrays_pointer > part_18.txt; then
    echo "Part 18 Runtime Error"
    exit 0
fi

if ! diff -i -w part_18.txt pe_resources/sum-arrays-pointer_out.txt; then
    echo "Part 18 Test Failed"
    exit 0
else
    echo "Part 18 Test Passed"
fi

rm -rf sum_arrays_pointer part_18.txt

if ! gcc src/list-char-types.c -o list_char_types; then
    echo "Part 19 compilation error"
    exit 0
fi

if ! ./list_char_types > part_19.txt; then
    echo "Part 19 Runtime Error"
    exit 0
fi

if ! diff -i -w part_19.txt pe_resources/list-char-types_out.txt; then
    echo "Part 19 Test Failed"
    exit 0
else
    echo "Part 19 Test Passed"
fi

rm -rf list_char_types part_19.txt

if ! gcc src/array_indexing.c -o array_indexing; then
    echo "Part 20 compilation error"
    exit 0
fi

if ! ./array_indexing > part_20.txt; then
    echo "Part 20 Runtime Error"
    exit 0
fi

if ! diff -i -w part_20.txt pe_resources/array_indexing_out.txt; then
    echo "Part 20 Test Failed"
    exit 0
else
    echo "Part 20 Test Passed"
fi

rm -rf array_indexing part_20.txt
