/**
 * arrays.c - Introductory examples of arrays in C
 * 
 * To compile the example, run this command...
 * 	gcc -o arrays arrays.c
 * 
 * To run the executable (after compiling)...
 * 	./arrays
 */


#include <stdio.h> /* printf */

/**
 * Arrays
 * One or more instances of a single type in a contiguous block of memory
 * 
 * Simple declaration of an array variable:
 * <type> <variable_name>[<array_size>];
 */

int main(void)
{
	/* Array variable `fibonacci_nums` of 8 integers set with initializer list of values */
	int fibonacci_nums[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };

	/* Accessing array elements by index (counting from 0) */
	int fifth_element = fibonacci_nums[4];   /*  5 */
	int seventh_element = fibonacci_nums[6]; /* 13 */

	/* Iterating over an array with a for loop */
	printf("Iterating over array with for loop...\n");

	int i;

	for (i = 0; i < 8; ++i) /* i: 0-7 */
	{
		printf("fibonacci_nums[%d] = %d\n", i, fibonacci_nums[i]);
	}

	/* Iterating over an array with a while loop */
	printf("\nIterating over array with while loop...\n");

	i = 0;

	while (i < 8) /* i: 0-7 */
	{
		printf("fibonacci_nums[%d] = %d\n", i, fibonacci_nums[i]);
		++i;
	}

	return 0;
}