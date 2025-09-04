#include <stdio.h>
// Exercise 2, Lesson 6: Concatenate all the unique strings
// entered in the command line.
// Print the concatted string with a comma and space between each word
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// Exercise 3, Lesson 6: Create a single string by concatenating all command
// line arguments, placing File scope variables are usually a no-no but it's OK
// to use them if they are constant
const int max_string_size = 10;
const int max_num_strings = 10;

bool this_string_is_unique (
    char         unique_strings[max_num_strings][max_string_size],
    unsigned int num_unique,
    char *       this_string)
{
    for (int idx = 0; idx < num_unique; idx++)
    {
        if (strncmp(unique_strings[idx], this_string, strlen(this_string)) == 0)
            return false;
        else
            return true;
    }

    return false;
}

bool args_are_ok (int argc, char * argv[])
{
    // Check for argc be sure it is > 3
    // Need at least two strings!
    if (argc < 3)
    {
        printf("Usage: concat-strings string1, string2, ..., stringn\n");
        printf("Must enter at least two strings\n");
        return false;
    }
    // Can't enter more than max_num_strings(10) strings
    if (argc > max_num_strings + 1)
    {
        printf("Cannot enter more than %d strings! You entered %d\n",
               max_num_strings,
               argc);
        return false;
    }
    // Check if each string entered is < max_string_size characters
    for (int idx = 1; idx < argc; idx++)
    {
        if (strlen(argv[idx]) > max_string_size)
        {
            printf("Argument \"%s\" exceeds %d characters\n",
                   argv[idx],
                   max_string_size);
            return false;
        }
    }

    return true;
}

int main (int argc, char * argv[])
{
    if (!args_are_ok(argc, argv))
        return EXIT_FAILURE;
    // Total size of strings
    unsigned int size_all_strings = 0;
    // Collection of unique strings
    // No more than max_num_strings strings each no more than max_string_size
    // characters
    char unique_strings[max_num_strings][max_string_size];
    // Need to keep track of number of unique strings
    unsigned int num_unique_strings = 0;

    // Skip program name in arg list!
    for (int idx = 1; idx < argc; ++idx)
    {
        // Let's see if this string is unique
        if (this_string_is_unique(
                unique_strings, num_unique_strings, argv[idx]))
        {
            // Add length to total size unique strings
            size_all_strings += strlen(argv[idx]);
            // Copy the unique string into the array of unique strings
            strcpy(unique_strings[num_unique_strings], argv[idx]);
            // Bump up the number of unique strings
            num_unique_strings++;
        }
    }
    // Print unique strings
    printf("These are the unique strings\n");
    for (int idx = 0; idx < num_unique_strings; idx++)
        printf("idx = %d unique string = %s\n", idx, unique_strings[idx]);

    // Use VLAs to create an array of characters that will
    // hold the concatenated unique words
    // Need to account for the comma and space between each unique word!
    char all_unique_words_as_one[size_all_strings + 2 * num_unique_strings + 1];
    // Above initialization fetches garbage in memory
    // The cat operation will scan above array until it hits a null
    // before concatenation
    // Let's go!
    for (int idx = 0; idx < num_unique_strings; idx++)
    {
        strcat(all_unique_words_as_one, unique_strings[idx]);
        // Don't cat a string on the last word!
        if (idx != num_unique_strings - 1)
            strcat(all_unique_words_as_one, ", ");
    }
    // Let's see!
    printf("All as one string: \"%s\"\n", all_unique_words_as_one);
}
