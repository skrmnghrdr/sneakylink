#!/bin/bash

if ! gcc src/find-string-length.c -o find-string-length; then
    echo "Part 21 compilation error"
    exit 0
fi

if ! ./find-string-length > part_21.txt; then
    echo "Part 21 Runtime Error"
    exit 0
fi

if ! diff -i -w part_21.txt pe_resources/find-string-length_out.txt; then
    echo "Part 21 Test Failed"
    exit 0
else
    echo "Part 21 Test Passed"
fi

rm -rf find-string-length part_21.txt

if ! gcc src/reverse-chars.c -o reverse_chars; then
    echo "Part 22 compilation error"
    exit 0
fi

if ! ./reverse_chars > part_22.txt; then
    echo "Part 22 Runtime Error"
    exit 0
fi

if ! diff -i -w part_22.txt pe_resources/reverse-chars_out.txt; then
    echo "Part 22 Test Failed"
    exit 0
else
    echo "Part 22 Test Passed"
fi

rm -rf reverse_chars part_22.txt

if ! gcc src/compute-min-max-avg.c -o compute_min_max_avg; then
    echo "Part 23 compilation error"
    exit 0
fi

if ! ./compute_min_max_avg > part_23.txt; then
    echo "Part 23 Runtime Error"
    exit 0
fi

if ! diff -i -w part_23.txt pe_resources/compute-min-max-avg_out.txt; then
    echo "Part 23 Test Failed"
    exit 0
else
    echo "Part 23 Test Passed"
fi

rm -rf compute_min_max_avg part_23.txt

if ! gcc src/reverse-chars-cmd-line.c -o rev-chars; then
    echo "Part 24 compilation error"
    exit 0
fi

if ! ./rev-chars "this is a long string" this_not 3456 > part_24.txt; then
    echo "Part 24 Runtime Error"
    exit 0
fi

if ! diff -i -w part_24.txt pe_resources/reverse-chars-cmd-line_out.txt; then
    echo "Part 24 Test Failed"
    exit 0
else
    echo "Part 24 Test Passed"
fi

rm -rf rev-chars part_24.txt

if ! gcc src/sum-arrays-with-function.c -o sum_arrays_with_function; then
    echo "Part 25 compilation error"
    exit 0
fi

if ! ./sum_arrays_with_function > part_25.txt; then
    echo "Part 25 Runtime Error"
    exit 0
fi

if ! diff -i -w part_25.txt pe_resources/sum-arrays-with-function_out.txt; then
    echo "Part 25 Test Failed"
    exit 0
else
    echo "Part 25 Test Passed"
fi

rm -rf sum_arrays_with_function part_25.txt

if ! gcc src/sum-arrays-with-pointer.c -o sum_arrays_with_pointer; then
    echo "Part 26 compilation error"
    exit 0
fi

if ! ./sum_arrays_with_pointer > part_26.txt; then
    echo "Part 26 Runtime Error"
    exit 0
fi

if ! diff -i -w part_26.txt pe_resources/sum-arrays-with-pointer_out.txt; then
    echo "Part 26 Test Failed"
    exit 0
else
    echo "Part 26 Test Passed"
fi

rm -rf sum_arrays_with_pointer part_26.txt