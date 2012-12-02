#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
unsigned invert(unsigned x, int p, int n);


int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	
	len = getLine(line, MAXLINE);
	
	if (len) {
		printf("The bits inverted number is: %d\n", invert(atoi(line), 7, 3));
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


/* invert: invert n bits to the right of p */
unsigned invert(unsigned x, int p, int n)
{
	unsigned mask;
	mask = ~(~0 << n);
	mask = mask << (p+1-n);
	return ((x & ~mask) + (~x & mask));
}