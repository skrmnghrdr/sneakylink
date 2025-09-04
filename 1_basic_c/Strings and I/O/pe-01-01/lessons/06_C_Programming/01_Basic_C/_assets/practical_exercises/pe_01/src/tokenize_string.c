#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum token_constants_t
{
    MAX_TOKENS    = 10,
    MAX_TOKEN_LEN = 50,
} token_constants_t;


// START WORK HERE

size_t tokstr (char * p_str,
               char * p_delim,
               char   token_arr[MAX_TOKENS][MAX_TOKEN_LEN])
{
    // Finish function
}

// END WORK HERE, DO NOT MODIFY PAST HERE

int main (int argc, char ** argv)
{
    int status = 1;

    if (2 != argc)
    {
        printf("Bad parameter, you must supply an input file\n");
        goto EXIT;
    }

    FILE * p_file = fopen(argv[1], "r");

    if (NULL == p_file)
    {
        perror("Could not open file");
        goto EXIT;
    }

    while (0 == feof(p_file))
    {
        char   phrase[510]         = { 0 };
        char   delim               = { 0 };
        size_t expected_elem_count = 0;
        int    scan_status         = fscanf(p_file,
                                 "\"%[^\"]\" \"%[^\"]\" %ld\n",
                                 phrase,
                                 &delim,
                                 &expected_elem_count);

        if (3 != scan_status)
        {
            perror("fscanf");
            goto EXIT;
        }

        char   token_arr[MAX_TOKENS][MAX_TOKEN_LEN] = { 0 };
        size_t ret_elem_count = tokstr(phrase, &delim, token_arr);

        if (ret_elem_count != expected_elem_count)
        {
            printf("Incorrect element count for delimiter\n");
            printf("Expected: %ld\nActual: %ld\n",
                   expected_elem_count,
                   ret_elem_count);
            status = 1;
            goto EXIT;
        }
    }

    status = 0;

EXIT:
    return (status);
}