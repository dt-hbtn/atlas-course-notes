/**
 * switch.c - Introductory examples of switch/case statement in C
 * 
 * To compile the example, run this command...
 * 	gcc -o switch switch.c
 * 
 * To run the executable (after compiling)...
 * 	./switch
 */


#include <stdio.h> /* printf */
#include <stdlib.h> /* rand, srand */
#include <time.h> /* time */

/**
 * Switch/case statement
 * Similar to conditional if/else but optimized to match specific (constant) values
 * 
 * USAGE:
 * 
 * switch (<variable_or_expression>) {
 * case <constant_value>:
 * 	// code for this case here
 * 	break;
 * 
 * // Additional cases...
 * 
 * default:
 * 	// code for default case (no cases matched)
 * 	break;
 * }
 * 
 */
int main(void)
{
	int value;

	srand(time(NULL));
	printf("Rolling dice...\n");

	value = rand() % 6 + 1; /* random value from 1-6 */

	switch (value) {
	case 1:	/* if (value == 1) */
		printf("⚀\n");
		break;
	case 2:	/* else if (value == 2) */
		printf("⚁\n");
		break;
	case 3:	/* else if (value == 3) */
		printf("⚂\n");
		break;
	case 4:	/* else if (value == 4) */
		printf("⚃\n");
		break;
	case 5:	/* else if (value == 5) */
		printf("⚄\n");
		break;
	case 6:	/* else if (value == 6) */
		printf("⚅\n");
		break;
	default: /* else */
		printf("Invalid roll!\n");
		break;
	}
	
	return 0;
}

