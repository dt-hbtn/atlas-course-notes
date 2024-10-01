# CS1100: Week 5

Code examples from class related to file I/O operations using the C standard library. There are examples of the following standard-library functions in the code (`#include <stdio.h>`):
- `fopen`: Opens a file stream given a file path
- `fclose`: Closes a file stream
- `fgets`: Reads characters into a buffer
- `fscanf`: Parses data from file stream according to a format string
- `fputs`: Writes a string to a file
- `fprintf`: Formats output and writes to file
- `fseek`: Moves to an arbitrary position in the file stream
- `ftell`: Returns the stream's current offset from the start of the file
- `rewind`: Moves stream position back to the start of the file

## Build/Run

To compile the example...
```bash
gcc -o file_io file_io.c -Wall -Werror -Wextra -pedantic
```

To run the example...
```bash
./file_io
```