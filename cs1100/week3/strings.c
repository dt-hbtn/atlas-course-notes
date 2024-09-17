/**
 * strings.c - Introductory examples of null-terminated strings in C
 * 
 * To compile the example, run this command...
 * 	gcc -o strings strings.c
 * 
 * To run the executable (after compiling)...
 * 	./strings
 */


#include <stdio.h> /* printf */
#include <string.h> /* strlen */

/**
 * Strings
 * An array of type `char` ending with a null-terminator (0 or '\0')
 */

int main(void)
{
	/* Initializing a `char` array with a string literal */
	char greeting[] = "hello, friend";

	/* `greeting` array has size of 14 (not 13), compiler adds null terminator */
	printf("Size of greeting array:    %lu\n", sizeof(greeting));
	printf("Length of greeting string: %lu\n", strlen(greeting));

	/* Iterating over character array with `for` loop (until null terminator is found) */
	printf("Iterating over string with while loop...\n");

	int i;

	for (i = 0; greeting[i] != '\0'; ++i) /* i: 0 - index of null terminator */
	{
		printf("greeting[%02d] = %c\n", i, greeting[i]);
	}

	/* Iterating over character array with `while` loop (until null terminator is found) */
	printf("\nIterating over string with while loop...\n");

	i = 0;

	while (greeting[i] != '\0')
	{
		printf("greeting[%02d] = %c\n", i, greeting[i]);
		++i;
	}

	return 0;
}
