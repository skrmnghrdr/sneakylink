#!/bin/bash

# Part 1 - sort_write_dups.c

if ! gcc -Wall -Werror src/sort_write_dups.c -o sort_write_dups; then
    echo "Part 1 Compilation Failed."
    exit 0
else
    echo "Part 1 Compiled."
fi

if ! echo "10" | ./sort_write_dups pe_resources/exercise1.txt sorted.txt > out.txt; then
    echo "Part 1 Test 1 Failed."
    ! cat out.txt
    exit 0
else
    echo "Part 1 Test 1 Passed!"
fi

rm -rf sort_write_dups out.txt sorted.txt

# Part 2 - sum_arrays.c

if ! gcc -Wall -Werror src/sum_arrays.c -o sum_arrays; then
    echo "Part 2 Compilation Failed."
    exit 0
else
    echo "Part 2 Compiled."
fi

if ! ./sum_arrays > out.txt; then
    echo "Part 2 Test 1 Failed to run."
    ! cat out.txt
    exit 0
else
    if ! diff -i -w out.txt expected_output/sum_array.txt > diff_out.txt; then
        echo "Part 2 Test 1 Wrong output."
        ! cat diff_out.txt
        exit 0
    else
        echo "Part 2 Test 1 Passed!"
    fi
fi

rm -rf sum_arrays out.txt diff_out.txt

# Part 3 - reverse_chars_cmd_line.c

if ! gcc -Wall -Werror src/reverse_chars_cmd_line.c -o reverse_chars_cmd_line; then
    echo "Part 3 Compilation Failed."
    exit 0
else
    echo "Part 3 Compiled."
fi

if ! ./reverse_chars_cmd_line "this is a long string" this_not 3456 > out.txt; then
    echo "Part 3 Test 1 Failed to run."
    ! cat out.txt
    exit 0
else
    if ! diff -i -w out.txt expected_output/rev_char.txt > diff_out.txt; then
        echo "Part 3 Test 1 Wrong output."
        ! cat diff_out.txt
        exit 0
    else
        echo "Part 3 Test 1 Passed!"
    fi
fi

rm -rf reverse_chars_cmd_line out.txt diff_out.txt

# Part 4 - concat_strings_commas.c

if ! gcc -Wall -Werror src/concat_strings_commas.c -o concat_strings_commas; then
    echo "Part 4 Compilation Failed."
    exit 0
else
    echo "Part 4 Compiled."
fi

if ! ./concat_strings_commas this is this has some some dups > out.txt; then
    echo "Part 4 Test 1 Failed to run."
    ! cat out.txt
    exit 0
else
    if ! diff out.txt expected_output/concat_strings_commas.txt > diff_out.txt; then
        echo "Part 4 Test 1 Wrong output."
        ! cat diff_out.txt
        exit 0
    else
        echo "Part 4 Test 1 Passed!"
    fi
fi

rm -rf concat_strings_commas out.txt diff_out.txt


# Part 5 - palindrome.c

if ! gcc -Wall -Werror src/palindrome.c -o palindrome; then
    echo "Part 5 Compilation Failed."
    exit 0
else
    echo "Part 5 Compiled."
fi

if ! ./palindrome > out.txt; then
    echo "Part 5 Test 1 Failed to run."
    ! cat out.txt
    exit 0
else
    if ! diff -i -w out.txt expected_output/palindrome.txt > diff_out.txt; then
        echo "Part 5 Test 1 Wrong output."
        ! cat diff_out.txt
        exit 0
    else
        echo "Part 5 Test 1 Passed!"
    fi
fi

rm -rf palindrome out.txt diff_out.txt