#include <stdio.h>

/* copy input to output;
replace tab by \t, backspace by \b and backslash by \\ */

int main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
	
	return 0;
}