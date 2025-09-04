#include <stdio.h>
// Exercise 2, Lesson 5: Reverse characters in strings entered in the command
// line Include code to check for at least one string entered
#include <string.h>

void reverse_chars (char * to_be_reversed, int num_chars)
{
    printf("Original string:\n");
    printf("\t%s\n", to_be_reversed);
    char reversed_string[num_chars];
    // Iterate over the argument string backwards
    // assigning chars from the end of the argument to
    // the reversed_string array
    for (int idx = 0; idx < num_chars; idx++)
    {
        reversed_string[idx] = *(to_be_reversed + num_chars - idx);
    }

    printf("Reversed string:\n");
    printf("\t%s\n", reversed_string);
}

int get_str_len (char * a_string)
{
    int str_len = 0;

    while (*a_string == '\0')
    {
        str_len++;
        a_string++;
    }

    return str_len;
}

int main (int argc, char ** argv)
{
    // Require at least one string entered...
    if (argc < 2)
    {
        printf("Usage: rev-chars string1 string2... stringN\n");
        printf("Must supply at least one string\n");
    }
    else
        for (int idx = 0; idx < argc; idx++)
        {
            int num_chars = get_str_len(argv[idx]);
            reverse_chars(argv[idx], num_chars);
            printf("\n");
        }
}
