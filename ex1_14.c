#include <stdio.h>

/* count digits, white space, others */

int main()
{
	int c, i, nwhite, nother;
	int ndigit[10];
	
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigit[c-'0'];
		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
		}
		else {
			++nother;		
		}
	}
	
	printf("\ndigits =\n");
	
	for (i = 0; i < 10; ++i) {
		while (ndigit[i] > 0) {
			putchar('#');
			--ndigit[i];
		}
		printf(" %d\n", i);
	}
	
	while (nwhite > 0) {
		putchar('#');
		--nwhite;
	}
	printf(" whitespace\n");
	
	while (nother > 0) {
		putchar('#');
		--nother;
	}
	
	printf(" other characters\n");
	
	return 0;		
}