#include <stdio.h>
#include <stdlib.h>

/**
 * open_file_and_close - Simply opens/closes an existing file
 * @filepath: Pointer to null-terminated string of file path
 *
 * Return: `0` on success, `-1` on failure
 */
int open_file_and_close(const char *filepath)
{
	/* FILE pointer for working with file stream */
	FILE *file_stream = NULL;

	/* Input validation ("sanity checks") */
	if (!filepath) {
		fputs("'filepath' cannot be NULL\n", stderr);
		return -1;
	}

	/* Open the file from streaming in read mode */
	file_stream = fopen(filepath, "r");

	/* If FILE pointer is NULL then `fopen` failed */
	if (!file_stream) {
		fprintf(stderr, "Could not open file '%s'\n", filepath);
		return -1;
	}

	fprintf(stderr, "Successfully opened file '%s'\n", filepath);

	/* Close the file */
	fclose(file_stream);
	return 0;
}

/**
 * create_file_and_close - Simply truncates an existing file or creates it
 * @filepath: Pointer to null-terminated string of file path
 *
 * Return: `0` on success, `-1` on failure
 */
int create_file_and_close(const char *filepath)
{
	/* FILE pointer for working with file stream */
	FILE *file_stream = NULL;

	/* Input validation ("sanity checks") */
	if (!filepath) {
		fputs("'filepath' cannot be NULL\n", stderr);
		return -1;
	}

	/* Open file in write mode (truncates file if it exists, creates it if it doesn't) */
	file_stream = fopen(filepath, "w");

	/* If FILE pointer is NULL then `fopen` failed */
	if (!file_stream) {
		fprintf(stderr, "Could not create empty file '%s'\n", filepath);
		return -1;
	}

	fprintf(stderr, "Successfully created empty file '%s'\n", filepath);

	/* Close the file */
	fclose(file_stream);
	return 0;
}

/**
 * append_to_file_and_close - Appends data to a file
 * @filepath: Pointer to null-terminated string of file path
 * @data: Pointer to null-terminated string of data to add
 *
 * Return: `0` on success, `-1` on failure
 */
int append_to_file_and_close(const char *filepath, const char *data)
{
	/* FILE pointer for working with file stream */
	FILE *file_stream = NULL;

	/* Input validation ("sanity checks") */
	if (!filepath) {
		fputs("'filepath' cannot be NULL\n", stderr);
		return -1;
	}
	if (!data) {
		fputs("'data' cannot be NULL\n", stderr);
		return -1;
	}

	/* Open file in append mode (writing will begin at the end of the file, no truncation) */
	file_stream = fopen(filepath, "a");

	/* If FILE pointer is NULL then `fopen` failed */
	if (!file_stream) {
		fprintf(stderr, "Could not opened file '%s'\n", filepath);
		return -1;
	}

	/* Write data to the end of the file */
	fprintf(file_stream, "New data: '%s'\n", data);

	/* Close the file */
	fclose(file_stream);
	return 0;
}

/**
 * read_int_from_file - Parses an `int` from a text file with `fscanf`
 * @filepath: Pointer to null-terminated string of file path
 * @out: Pointer to `int` where parsed value will be stored
 *
 * Return: `0` on success, `-1` on failure
 */
int read_int_from_file(const char *filepath, int *out)
{
	/* FILE pointer for working with file stream */
	FILE *file_stream = NULL;
	int items_scanned;

	/* Input validation ("sanity checks") */
	if (!filepath) {
		fputs("'filepath' cannot be NULL\n", stderr);
		return -1;
	}

	/* Open file in read mode */
	file_stream = fopen(filepath, "r");

	/* If FILE pointer is NULL then `fopen` failed */
	if (!file_stream) {
		fprintf(stderr, "Could not open file '%s'\n", filepath);
		return -1;
	}

	fprintf(stderr, "Successfully opened file '%s'\n", filepath);

	/* Parsing int from first line with `fscanf` */
	items_scanned = fscanf(file_stream, "really important data: %d", out);
	fprintf(stderr, "%d items scanned from file\n", items_scanned);

	/* Close the file */
	fclose(file_stream);
	return 0;
}

/**
 * jump_around_file - Demonstrates file navigation with `fseek`, `ftell`, `rewind`
 * @filepath: Pointer to null-terminated string of file path
 *
 * Return: `0` on success, `-1` on failure
 */
int jump_around_file(const char *filepath)
{
	/* FILE pointer for working with file stream */
	FILE *file_stream = NULL;
	long file_offset;

	/* Input validation ("sanity checks") */
	if (!filepath) {
		fputs("'filepath' cannot be NULL\n", stderr);
		return -1;
	}

	/* Open file in read mode */
	file_stream = fopen(filepath, "r");

	/* If FILE pointer is NULL then `fopen` failed */
	if (!file_stream) {
		fprintf(stderr, "Could not open file '%s'\n", filepath);
		return -1;
	}

	fprintf(stderr, "Successfully opened file '%s'\n", filepath);

	/* Initial file offset should be 0 */
	file_offset = ftell(file_stream);
	fprintf(stderr, "Current file offset: %ld\n", file_offset);

	/* Moving 13 bytes forward from current position (SEEK_CUR) */
	fseek(file_stream, 13, SEEK_CUR);

	/* Offset should now be 13 */
	file_offset = ftell(file_stream);
	fprintf(stderr, "Current file offset: %ld\n", file_offset);

	/* Moving 4 bytes before the end of the file (SEEK_END) */
	fseek(file_stream, -4, SEEK_END);

	/* Offset should now be (file_size - 4) */
	file_offset = ftell(file_stream);
	fprintf(stderr, "Current file offset: %ld\n", file_offset);

	/* Moving to the beginning of the file */
	rewind(file_stream); /* fseek(file_stream, 0, SEEK_SET); */

	/* Offset should now be 0 again */
	file_offset = ftell(file_stream);
	fprintf(stderr, "Current file offset: %ld\n", file_offset);

	/* Close the file */
	fclose(file_stream);
	return 0;
}

#define TESTFILE "filethatexists.txt"

int main(void)
{
	int result;
	int int_from_file;

	// result = open_file_and_close(TESTFILE);
	// result = append_to_file_and_close(TESTFILE, "hello there");
	// result = jump_around_file(TESTFILE);
	result = read_int_from_file(TESTFILE, &int_from_file);
	fprintf(stderr, "function returned %d\n", result);
	printf("Integer parsed from file: %d\n", int_from_file);
	return 0;
}
