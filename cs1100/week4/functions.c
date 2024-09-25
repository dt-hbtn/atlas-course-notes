#include <string.h>
#include "functions.h"

/**
 * Reverses a string in-place using array indices
 * @param[in] string
 * @param[out] reversed_string
 */
char *reverse_string_by_index(char *string)
{
	int left, right; /* start at the bookends and converge */
	char tmp; /* temporary character variable to facilitate swapping */

	if (!string) /* checking to make sure we haven't been passed a NULL pointer (would cause Segmentation Fault) */
		return NULL; /* returning NULL indicates user error */
	
	if (string[0] == '\0') /* string is empty, so reversing it is a no-op */
		return string;

	left = 0;
	right = (int)strlen(string) - 1;

	for (; left <= right; ++left, --right) {
		/* swap characters at `left` and `right` indices */
		tmp = string[left];
		string[left] = string[right];
		string[right] = tmp;
	}

	return string;
}

/**
 * Reverses a string in-place using pointers
 * @param[in] string
 * @param[out] reversed_string
 */
char *reverse_string_with_pointers(char *string)
{
	char *left = NULL, *right = NULL; /* start at the bookends and converge (good habit to initialize pointers to NULL) */
	char tmp; /* temporary character variable to facilitate swapping */

	if (!string) /* checking to make sure we haven't been passed a NULL pointer (would cause Segmentation Fault) */
		return NULL; /* returning NULL indicates user error */

	if (string[0] == '\0') /* string is empty, so reversing it is a no-op */
		return string;

	left = string; /* pointer to first character */
	right = left + (strlen(string) - 1); /* pointer to last character */

	/* use pointer arithmetic to perform the same algorithm as `reverse_string_by_index` */
	for (; left <= right; ++left, --right) {
		/* swap characters at `left` and `right` indices */
		tmp = *left; /* just dereference the pointers instead of using indices */
		*left = *right;
		*right = tmp;
	}

	return string;
}
