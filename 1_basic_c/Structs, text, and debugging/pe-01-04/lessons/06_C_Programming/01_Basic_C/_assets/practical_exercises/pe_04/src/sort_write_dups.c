#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
// Exercise 1, Lesson 7: Read a file containing integers from 0 to 100, 5
// numbers per line and extract/print the unique integers for 500 numbers

bool this_number_is_unique (int check_this_num,
                            int num_unique,
                            int unique_nums[num_unique])
{
    int unique_num_idx = 0;

    while (unique_num_idx < num_unique)
    {
        if (check_this_num == unique_nums[unique_num_idx++])
        {
            return false;
        }
    }

    return true;
}

int main (int argc, char ** argv)
{
    int status = -1;

    if (3 != argc)
    {
        printf("Usage: %s <infile> <outfile>\n", argv[0]);
        goto EXIT;
    }

    int num_from_file    = 0;
    int unique_nums[500] = { 0 };
    int num_unique       = 0;

    FILE * p_num_stream = fopen(argv[1], "r");

    // Open the input file
    if (NULL == p_num_stream)
    {
        perror("Could not open file");
        goto EXIT;
    }

    // Read numbers from the file and store unique ones
    while (1 == fscanf(p_num_stream, "%d", &num_from_file))
    {
        if (this_number_is_unique(num_from_file, num_unique, unique_nums))
        {
            unique_nums[num_unique++] = num_from_file;
        }
    }

    if (0 != fclose(p_num_stream))
    {
        perror("fclose num file");
    }

    // Print out unique numbers - 10 to a line
    // The numbers are ALREADY SORTED - just suppress the printing
    // of the '0' elements (recall the unique array was initialized to 0)

    // Need a separate counter for the printed items
    // Can't use array index - we'll not get 10 to a line!
    int print_idx = 0;
    for (int uidx = 0; uidx < 500; uidx++)
    {
        if (unique_nums[uidx] != 0)
            printf("%d  %s",
                   unique_nums[uidx],
                   (print_idx++ % 10 == 9) ? "\n" : " ");
    }
    putchar('\n');

    // No need for another stream file handle - we already have one declared
    p_num_stream = fopen(argv[2], "w");

    if (NULL == p_num_stream)
    {
        perror("Could not open file");
        goto EXIT;
    }

    // OK - use the same print statement only with fprintf
    print_idx = 0;

    for (int uidx = 0; uidx < 500; uidx++)
    {
        if (0 != unique_nums[uidx])
        {
            fprintf(p_num_stream,
                    "%d  %s",
                    unique_nums[uidx],
                    (print_idx++ % 10 == 9) ? "\n" : " ");
            // Check for an error
            if (ferror(p_num_stream))
            {
                perror("Error with call to fprintf");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(p_num_stream);

    status = 0;

EXIT:
    return (status);
}