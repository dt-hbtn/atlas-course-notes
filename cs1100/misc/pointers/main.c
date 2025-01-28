#include <stdlib.h>
#include <stdio.h>

void reverse_string_with_index(char *string);
void reverse_string_with_pointers(char *string);


int main(int argc, char **argv)
{
	char *string = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s STRING\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	string = argv[1];
	reverse_string_with_pointers(string);
	puts(string);
	return 0;
}
