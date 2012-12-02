#include <stdio.h>

/* copy input to output;
replace one or more blanks by a single blank */
	
int main()
{
	int prev, c;
	prev = 0;
	
	while ((c = getchar()) != EOF) {
		if (prev == ' ' || prev == '\t' || prev == '\n') {
			if (c == ' ' || c == '\t' || c == '\n') {
				prev = c;
				continue;				
			}
		}
		
		putchar(c);
		prev = c;
	}
	
	return 0;
}