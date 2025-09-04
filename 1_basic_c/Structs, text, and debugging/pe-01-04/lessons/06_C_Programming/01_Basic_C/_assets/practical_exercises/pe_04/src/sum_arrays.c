#include <stdio.h>

// Exercise 2, day 4: Sum elements of the inner dimension of a 2-D array
// and save them in another array
int main (void)
{
    /* an array with 5 rows and 2 columns*/
    int nums[5][2] = { { 10, 100 }, { 20, 200 }, { 2, 4 }, { 3, 6 }, { 4, 8 } };

    // Get the sizes instead of hardcoding array bounds
    int num_inner = sizeof(nums[0]) / sizeof(int);
    int num_outer = sizeof(nums) / sizeof(nums[0]);

    // Create the array of sums using a Variable-length array
    // C does not permit initializing a VLA
    int sums[num_outer];

    printf("Number of elements, inner dimension: %d \n", num_inner);
    printf("Number of elements, outer dimension: %d \n\n", num_outer);

    // Loop over the arrays, accummulating the required sums
    for (int outer = 0; outer < num_outer; outer++)
    {
        // Need to initialize the sum array element here!
        // All variables MUST be initialized before use as an rvalue!
        sums[outer] = 0;
        for (int inner = 0; inner < num_inner; inner++)
        {
            // sums[outer] used as rvalue here!
            sums[outer] =+ nums[outer][inner];
        }
    }
    // Print out the sums:
    printf("The sums of the inner array elements are: ");
    for (int sidx = 0; sidx < num_outer; sidx++)
        printf("%d ", sums[sidx]);
    printf("\n");
}
