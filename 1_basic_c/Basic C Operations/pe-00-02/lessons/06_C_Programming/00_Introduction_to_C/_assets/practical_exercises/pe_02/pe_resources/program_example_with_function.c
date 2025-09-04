#include <stdio.h>

/* This program is the same as 'commented_program_example.c' except
 * this program uses FUNCTIONS to compute and print Worf's age
*/

// This is a function DECLARATION. All functions in C must be
// declared (or defined) before use.
// This declaration tells the C compiler that this function takes two
// INTEGERS as arguments and returns an INTEGER
// This declaration is called a FUNCTION PROTOTYPE

// ALL functions require code for execution. This program cannot use
// this function until the function has code enclosed in curlies that
// do 'actual work'
int compute_worfs_age(int current_year, int year_born);

// This is a function DEFINITION. The definition is a declaration PLUS 
// the code that does the 'actual work'
//
// void is a C keyword that tells the compiler that this function
// DOES NOT return a value. 
void print_worfs_age(int worfs_age)
{
	// Discuss - why is a_great_warrior[] defined here instead of main()?
	char a_great_warrior[] = "Worf, son of Mogh";

	// The printf() function was declared in stdio.h
	printf("%s is %d years old\n", a_great_warrior, worfs_age);
}

int main(int argc, char **argv)
{
	int birth_year;
	int year_now = 140;
	birth_year = 100;

	// CALL the function to compute Worf's age and RETURN the result
	// to the main() function
	int the_sum = compute_worfs_age(year_now, birth_year);

	// CALL the function to print the result
	print_worfs_age(the_sum);

	return 0;
}

// The function 'compute_worfs_age' is DECLARED above but the program 
// requires a DEFINITION before the function may be called.
int compute_worfs_age(int current_year, int year_born)
{

	// The return value is made available to the main() function
	// in the variable 'the_sum' defined in the main() function
	return current_year - year_born;
}

/*
 * This program when executed produces:
 * 
 * Worf, son of Mogh is 110 years old
 * 
*/
