#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100	/* maximum input line length */

int htoi(char s[]);
int getLine(char line[], int maxline);

/* print the longest input line */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	
	len = getLine(line, MAXLINE);
	if (len > 0) {
		printf("\nThe number is: %d\n", htoi(line));
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


/* convert hexadecimal to integer */
int htoi(char s[])
{
	int i = 0;
	while (s[i] == ' ' || s[i] == '\t') {
		++i;
	}
	
	if ((s[i] == '0') && (tolower(s[i+1]) == 'x')) {
		++i;
		++i;
	}
	
	int n = 0;
	int term;
	while (s[i] != '\0' && s[i] != '\n') {
		char c = tolower(s[i]);
		if (c >= '0' && c <= '9') {
			term = c - '0';
		} else if ((c - 'a') <= 6) {
			term = 10 + c - 'a';
		} else {
			break;
		}
		++i;
		n = (n * 16) + term;
	}
	
	return n;
}