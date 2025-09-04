#include <stdio.h>
#include <stdbool.h>

// Print all palindrome substrings of a given string, if any
int get_str_len (char * a_string)
{
    int str_len = 0;
    while (*a_string != '\0')
    {
        str_len++;
        a_string++;
    }

    return str_len;
}

bool is_palindrome (char * string)
{
    int    str_length = get_str_len(string);
    char * back_str   = string;
    int    back_idx   = 1;

    while (*back_str != '\0')
    {
        if (*back_str++ != *(back_str + (str_length - back_idx++)))
            return false;
    }
    return true;
}

void find_palindrome_substrings (char * a_string)
{
    int  str_length = get_str_len(a_string);
    char substring[str_length];
    for (int str_idx = 0; str_idx < str_length; str_idx++)
    {
        int substr_size          = 0;
        substring[substr_size++] = a_string[str_idx];

        for (int inn_idx = str_idx + 1; inn_idx < str_length; inn_idx++)
        {
            substring[substr_size] = a_string[inn_idx];

            if (is_palindrome(substring))
                printf("'%s' is a palindrome substring of '%s'\n",
                       substring,
                       a_string);
        }
    }
}

int main (void)
{
    char * strings[] = { "thissi is abba string",
                         "notot so thissi",
                         "itopinonavevanonipoti" };
    for (int str_i = 0; str_i < sizeof(strings) / sizeof(char *); str_i++)
    {

        char * a_string = strings[str_i];
        find_palindrome_substrings(a_string);

        printf("\n");
    }
}
