#include <stddef.h>	/* size_t */
#include <string.h>	/* strlen */

void reverse_string_with_index(char *string)
{
	size_t i, j;
	char tmp;

	if (string == NULL || string[0] == '\0')
		return;

	/* `i` moves forward from the start */
	i = 0;
	/* `j` moves backward from the end */
	j = strlen(string) - 1;

	while (i < j) {
		/* swap the characters */
		tmp = string[i];
		string[i] = string[j];
		string[j] = tmp;
		/* move `i` forward, `j` backward */
		++i;
		--j;
	}
}


void reverse_string_with_pointers(char *string)
{
	char *l_ptr = NULL, *r_ptr = NULL;
	char tmp;

	if (string == NULL || string[0] == '\0')
		return;

	/* `l_ptr` moves forward from the start */
	l_ptr = string;
	/* `r_ptr` moves backward from the end */
	r_ptr = string + (strlen(string) - 1);

	while (l_ptr < r_ptr) {
		/* swap the characters */
		tmp = *l_ptr;
		*l_ptr = *r_ptr;
		*r_ptr = tmp;
		/* move `l_ptr` forward, `r_ptr` backward */
		++l_ptr;
		--r_ptr;
	}
}
