/**
 * pointers.c - Introductory examples of pointers in C
 * 
 * To compile the example, run this command...
 * 	gcc -o pointers pointers.c
 * 
 * To run the executable (after compiling)...
 * 	./pointers
 */


#include <stdio.h> /* printf */

/**
 * Pointers
 * Store the memory address of another variable
 */

int main(void)
{
	/* Declare and initialize 3 int variables */
	int x = 120, y = 121, z = 122;

	/**
	 * Declare 3 pointer-to-int variables
	 * p1, p2, and p3 are variables that each store a memory address for another int variable
	 * The pointers are initialized to `NULL` meaning they do not point to a valid memory address.
	 */
	int *p1 = NULL;
	int *p2 = NULL;
	int *p3 = NULL;

	/**
	 * & = "address of" operator
	 * Use the & operator to assign addresses of x, y, and z to p1, p2, and p3, respectively
	 */
	p1 = &x; /* memory address of x */
	p2 = &y; /* memory address of y */
	p3 = &z; /* memory address of z */

	/* Dereference values from pointers with * operator */

	int xx, yy, zz;

	xx = *p1; /* value at address p1 */
	yy = *p2; /* value at address p2 */
	zz = *p3; /* value at address p3 */

	/* Changing xx value will not affect x, but changing the value at p1 address will change x */
	printf("Printing initial values...\n");
	printf("x=%d y=%d z=%d\n", x, y, z);
	printf("p2 points to y...so altering the value at address p2 will change y\n");

	*p2 -= 32; /* subtracting 32 from the value at address p2 */

	printf("Notice the value of y has changed...\n");
	printf("x=%d y=%d z=%d\n", x, y, z);

	return 0;
}
