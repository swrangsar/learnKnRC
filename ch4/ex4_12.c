#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void reverse(char s[]);
void itoa(int n, int carryforward);

/* expand shorthand notations */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			itoa(atoi(line), 0);
			putchar('\n');
		}		
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


/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


/* itoa: convert n to characters in s */
void itoa(int n, int carryforward)
{
	if (n < 0) {
		putchar('-');
		n = -n;		
	}
	int carry;
	carry = carryforward;
	if (n == INT_MIN) {
		carry = 1;
		n = -(n+1);
	}
	if ((n%10 + carry) > 9)
		carryforward = 1;
	if (n/10)
		itoa(n/10, carryforward);
	else if (carryforward)
		putchar('1');
	putchar(n%10 + '0' + carry);	
}