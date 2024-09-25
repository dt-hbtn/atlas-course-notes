#ifndef CS1100_FUNCTIONS_H
#define CS1100_FUNCTIONS_H

/* Comments below are a commonly used convention for documenting functions */

/**
 * Reverses a string in-place using array indices
 * @param[in] string
 * @param[out] reversed_string
 */
char *reverse_string_by_index(char *string);

/**
 * Reverses a string in-place using pointers
 * @param[in] string
 * @param[out] reversed_string
 */
char *reverse_string_with_pointers(char *string);

#endif /* !CS1100_FUNCTIONS_H */
