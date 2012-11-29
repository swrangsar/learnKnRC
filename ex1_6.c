#include <stdio.h>

/* copy input to output; 2nd version */

int main()
{
	int c;
	c = 1;
	/* while ((c = getchar()) != EOF)
		putchar(c); */
	
	printf("The value: %d\n", getchar() != EOF);
	return 0;
}