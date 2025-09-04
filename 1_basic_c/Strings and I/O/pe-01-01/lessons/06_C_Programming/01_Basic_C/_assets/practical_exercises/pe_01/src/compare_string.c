#include <string.h>
#include <stdio.h>

// START WORK HERE

/**
 * @brief Compares two strings
 *
 * @param p_str1 First string
 * @param p_str2 Second string to compare
 * @return int
 * @retval 0 Strings are equal
 * @retval < 0 p_str1 is less than p_str2
 * @retval > 0 p_str1 is greater than p_str2
 */
int cmpstr (char * p_str1, char * p_str2)
{
    int status = -1;

    // Finish function

EXIT:
    return status;
}

// END WORK HERE, DO NOT MODIFY PAST HERE

/**
 * @brief Returns the sign
 *
 * @param x
 * @return int
 */
int sign (int x)
{
    return (x > 0) - (x < 0);
}

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
        char word1[50]       = { 0 };
        char word2[50]       = { 0 };
        int  expected_retval = 0;

        int scan_status
            = fscanf(p_file, "%s %s %d", word1, word2, &expected_retval);

        if (3 != scan_status)
        {
            perror("fscanf");
            goto EXIT;
        }

        int cmp_retval = cmpstr(word1, word2);

        // Only take the positive, negative, or zero value in range of -1, 0, 1
        cmp_retval = (cmp_retval > 0) - (cmp_retval < 0);

        if (expected_retval != cmp_retval)
        {
            printf("%s %s\nExpected:\t%d\nActual:\t\t%d\n",
                   word1,
                   word2,
                   expected_retval,
                   cmpstr(word1, word2));
            goto EXIT;
        }
    }

    status = 0;

EXIT:
    return (status);
}