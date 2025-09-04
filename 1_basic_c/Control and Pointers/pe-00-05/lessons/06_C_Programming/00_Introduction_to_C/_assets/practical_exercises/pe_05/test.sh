#!/bin/bash

if ! gcc src/type-info.c -o type-info; then
    echo "Part 14 compilation error"
    exit 0
fi

if ! ./type-info > part_14.txt; then
    echo "Part 14 Runtime Error"
    exit 0
fi

if ! diff -i -w part_14.txt pe_resources/type-info_out.txt; then
    echo "Part 14 Test Failed"
    exit 0
else
    echo "Part 14 Test Passed"
fi

rm -rf type-info part_14.txt

if ! gcc src/temp-conversion.c -o temp-conversion; then
    echo "Part 15 compilation error"
    exit 0
fi

if ! ./temp-conversion > part_15.txt; then
    echo "Part 15 Runtime Error"
    exit 0
fi

if ! diff -i -w part_15.txt pe_resources/temp-conversion_out.txt; then
    echo "Part 15 Test Failed"
    exit 0
else
    echo "Part 15 Test Passed"
fi

rm -rf temp-conversion part_15.txt
