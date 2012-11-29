#include <stdio.h>

/* count blanks, tabs and newlines */

int main()
{
	int c, count;
	count = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ')
			++count;
	}
	
	printf("The number of blanks is: %d\n", count);
	
	return 0;
}