#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
unsigned setbits(unsigned x, int p, int n, unsigned y);


int main()
{
	int len1, len2;	/* current line length */
	char line1[MAXLINE], line2[MAXLINE];	/* current input line */
	
	len1 = getLine(line1, MAXLINE);
	len2 = getLine(line2, MAXLINE);
	
	if (len1 && len2) {
		printf("The bit set number is: %d\n", setbits(atoi(line1), 7, 3, atoi(line2)));
	}
		
	return 0;
}


/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	
	return i;
}


/* setbits: x with n bits of y at position p of x */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	y = y & ~(~0 << n);
	y = y << (p+1-n);
	unsigned mask;
	mask = ~(~0 << n);
	mask = mask << (p+1-n);
	x = x & ~mask;
	return (x + y);
}