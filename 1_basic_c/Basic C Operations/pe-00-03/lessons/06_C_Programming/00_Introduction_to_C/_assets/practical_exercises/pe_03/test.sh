# Part 7

if ! gcc -Wall -Werror src/eval-expressions.c -o eval-expressions; then
    echo "Part 7 compilation error"
    exit 0
fi

if ! ./eval-expressions > part_7.txt; then
    echo "Part 7 runtime error"
    exit 0
fi

if ! diff -q -i -w part_7.txt pe_resources/eval-expressions_out.txt > /dev/null; then
    echo "Part 7 Test Failed"
    exit 0
else
    echo "Part 7 Test Passed"
fi

rm -rf eval-expressions part_7.txt

# Part 8

if ! gcc -Wall -Werror src/ternary.c -o ternary; then
    echo "Part 8 compilation error"
    exit 0
fi

if ! ./ternary > part_8.txt; then
    echo "Part 8 runtime error"
    exit 0
fi

if ! diff -q -i -w part_8.txt pe_resources/ternary_out.txt > /dev/null; then
    echo "Part 8 Test Failed"
    exit 0
else
    echo "Part 8 Test Passed"
fi

rm -rf ternary part_8.txt

# Part 9
if ! gcc -Wall -Werror src/operators.c -o operators; then
    echo "Part 9 compilation error"
    exit 0
fi

if ! ./operators > part_9.txt; then
    echo "Part 9 runtime error"
    exit 0
fi

if ! diff -q -i -w part_9.txt pe_resources/operators_out.txt ; then
    echo "Part 9 Test Failed"
    exit 0
else
    echo "Part 9 Test Passed"
fi

rm -rf operators part_9.txt

# Part 10
if ! gcc -Wall -Werror src/relational-logical.c -o relational-logical; then
    echo "Part 10 compilation error"
    exit 0
fi

if ! ./relational-logical > part_10.txt; then
    echo "Part 10 runtime error"
    exit 0
fi

if ! diff -q -i -w part_10.txt pe_resources/relational-logical_out.txt > /dev/null; then
    echo "Part 10 Test Failed"
    exit 0
else
    echo "Part 10 Test Passed"
fi

rm -rf relational-logical part_10.txt

# Part 11
if ! gcc -Wall -Werror src/part11/fetchprog.c src/part11/mainprog.c -Iexample_solution/part11 -o fetch-employee; then
    echo "Part 11 compilation error"
    exit 0
fi

if ! ./fetch-employee > part_11.txt; then
    echo "Part 11 runtime error"
    exit 0
fi

if ! diff -q -i -w part_11.txt pe_resources/fetch-employee_out.txt > /dev/null; then
    echo "Part 11 Test Failed"
    exit 0
else
    echo "Part 11 Test Passed"
fi

rm -rf fetch-employee part_11.txt
