#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
unsigned rightrot(unsigned x, int n);
unsigned getUnsignedSize(void);


int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	
	len = getLine(line, MAXLINE);
	
	if (len) {
		printf("The bits inverted number is: %u\n", rightrot(atoi(line), 3));
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

/* get no. of bits for unsigned ints */
unsigned getUnsignedSize(void)
{
	unsigned x, i;
	i = 0;
	x = ~0;
	while (x != 0) {
		x = x >> 1;
		++i;
	}
	return i;
}


/* invert: invert n bits to the right of p */
unsigned rightrot(unsigned x, int n)
{
	unsigned maxBits;
	maxBits = getUnsignedSize();
	
	return ((x >> n) | (x << (maxBits-n)));
}