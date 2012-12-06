#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void reverse(char s[]);
void itob(int n, char s[], int b);


int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	char expandedLine[MAXLINE];	/* longest line saved here */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			itob(atoi(line), expandedLine, 16);
			printf("%s\n", expandedLine);
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
void itob(int n, char s[], int b)
{
	int i, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	
	i = 0;
	do {
		if ((n%b) < 10)
			s[i++] = n%b + '0';
		else 
			s[i++] = n%b + 'a' - 10;
	} while ((n /= b) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	
	
	reverse(s);
}