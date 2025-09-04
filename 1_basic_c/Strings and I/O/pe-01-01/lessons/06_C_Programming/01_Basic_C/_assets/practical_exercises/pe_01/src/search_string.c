#include <stdio.h>
#include <string.h>

// START WORK HERE

char * findstr (char * p_haystack, char * p_needle)
{
    char * p_retval = NULL;

    // Finish function

EXIT:
    return (p_retval);
}

// END WORK HERE, DO NOT MODIFY PAST HERE

int main (int argc, char ** argv)
{
    int status = -1;

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
        char haystack[50] = { 0 };
        char needle[50]   = { 0 };
        int  scan_status
            = fscanf(p_file, "\"%[^\"]\" \"%[^\"]\"\n", haystack, needle);

        if (2 != scan_status)
        {
            perror("fscanf");
            goto EXIT;
        }

        size_t needle_len = strlen(needle);
        char * p_needle   = findstr(haystack, needle);

        if (0 != strncmp(needle, p_needle, needle_len))
        {
            printf("Incorrect needle/needle not found\n");
            goto EXIT;
        }
    }

    status = 0;

EXIT:
    return (status);
}