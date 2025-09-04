#!/bin/bash

if ! gcc -Wall -Werror src/do_arithmetic.c -o do_arithmetic; then
    echo "Part 2 Compilation Failed"
    exit 0
fi

./do_arithmetic > part_2_student_out.txt

if diff -q -i -w part_2_student_out.txt pe_resources/arithmetic_out.txt; then
    echo "PE Part 2 Passed"
else
    echo "PE Part 2 Failed"
    exit 0
fi

rm -rf do_arithmetic part_2_student_out.txt

if ! gcc -Wall -Werror src/do_arithmetic_with_funcs.c -o do_arithmetic; then
    echo "Part 3 Compilation Failed"
    exit 0
fi

./do_arithmetic > part_3_student_out.txt

if diff -q -i -w part_3_student_out.txt pe_resources/arithmetic_out.txt; then
    echo "PE Part 3 Passed"
else
    echo "PE Part 3 Failed"
    exit 0
fi

rm -rf do_arithmetic part_3_student_out.txt

if ! gcc -Wall -Werror src/do_arithmetic_with_more_funcs.c -o do_arithmetic; then
    echo "Part 4 Compilation Failed"
    exit 0
fi

./do_arithmetic > part_4_student_out.txt

if diff -q -i -w part_4_student_out.txt pe_resources/arithmetic_out.txt; then
    echo "PE Part 4 Passed"
else
    echo "PE Part 4 Failed"
    exit 0
fi

rm -rf do_arithmetic part_4_student_out.txt

if ! gcc -Wall -Werror src/do_arithmetic_with_header.c src/arithmetic_print_funcs.c -o do_arithmetic; then
    echo "Part 5 Compilation Failed"
    exit 0
fi

./do_arithmetic > part_5_student_out.txt

if diff -q -i -w part_5_student_out.txt pe_resources/arithmetic_out.txt; then
    echo "PE Part 5 Passed"
else
    echo "PE Part 5 Failed"
    exit 0
fi

rm -rf do_arithmetic part_5_student_out.txt

if ! make -C src/ > /dev/null; then
    echo "Part 6 Compilation Failed"
    exit 0
fi

./src/do_arithmetic > part_6_student_out.txt

if diff -q -i -w part_6_student_out.txt pe_resources/arithmetic_out.txt; then
    echo "PE Part 6 Passed"
else
    echo "PE Part 6 Failed"
    exit 0
fi

rm -rf src/do_arithmetic part_6_student_out.txt
