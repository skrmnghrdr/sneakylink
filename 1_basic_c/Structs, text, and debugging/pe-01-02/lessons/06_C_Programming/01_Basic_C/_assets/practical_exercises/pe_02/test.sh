#!/bin/bash

if ! gcc -Wall -Werror src/list_file_info.c -o list_file_info; then
    echo "Part 1 Compilation Failed."
else
    echo "Part 1 Compiled."
fi

# Creating fake folder with a bunch of items for known output

# Create the main directory
mkdir -p /tmp/fake_folder

# Navigate into the directory
cd /tmp/fake_folder

# Create subdirectories and files with junk data
for i in {1..5}; do
    mkdir "subdir_$i"
done

# Create additional files in the main directory
for i in {1..5}; do
    echo "Creating junk data in file$i.txt"
    touch "file$i.txt"
    base64 /dev/urandom | head -c 1000 > "file$i.txt"
done

# Navigate back to the original directory
cd -

if ! ls /tmp/fake_folder | ./list_file_info /tmp/fake_folder > out.txt; then
    echo "Part 1 Test Failed"
    exit 0
else
    if ! diff -i -w out.txt expected_output/list_file_info.txt > diff_out.txt; then
        echo "Part 1 Test 1 Wrong output."
        ! cat diff_out.txt
        exit 0
    else
        echo "Part 1 Test Passed!"
    fi
fi

rm -rf list_file_info out.txt diff_out.txt /tmp/fake_folder

