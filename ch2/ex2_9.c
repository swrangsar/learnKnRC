#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
int bitcount(int x);

int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	
	len = getLine(line, MAXLINE);
	
	if (len) {
		printf("The number of 1-bits is: %d\n", bitcount(atoi(line))``);
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


/* bitcount: count the number of 1-bits in x */
int bitcount(int x)
{
	int i = 0;
	while (x) {
		x &= (x-1);
		++i;
	}
	return i;
}
