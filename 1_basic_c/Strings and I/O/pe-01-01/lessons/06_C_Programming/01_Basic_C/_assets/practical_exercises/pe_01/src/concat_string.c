#include <stdio.h>
#include <string.h>

// START WORK HERE

char * catstr (char * p_dest, char * p_src)
{
    char * p_retval = NULL;

    // Finish function

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
        char word1[50]            = { 0 };
        char word2[50]            = { 0 };
        char expected_concat[100] = { 0 };
        int  scan_status
            = fscanf(p_file, "%s %s %s", word1, word2, expected_concat);

        if (3 != scan_status)
        {
            perror("fscanf");
            goto EXIT;
        }

        char * p_concat = catstr(word1, word2);

        if (0 != strcmp(p_concat, expected_concat))
        {
            printf("%s %s\nExpected:\t%s\nActual:\t\t%s\n",
                   word1,
                   word2,
                   expected_concat,
                   p_concat);
            goto EXIT;
        }
    }

    status = 0;

EXIT:
    return (status);
}