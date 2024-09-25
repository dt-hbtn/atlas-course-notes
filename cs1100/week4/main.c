#include <stdio.h>
#include "functions.h"

int main(void)
{
	char test_string[] = "hello, friend";

	printf("Original string: %s\n\n", test_string);
	printf("reverse_string_by_index(\"%s\")\n", test_string);
	printf("Reversed string: %s\n\n", reverse_string_by_index(test_string));
	printf("reverse_string_with_pointers(\"%s\")\n", test_string);
	printf("Reversed string: %s\n", reverse_string_with_pointers(test_string));

	return 0;
}
