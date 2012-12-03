#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
int lower(int c);
void lowerString(char s[]);


int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	
	len = getLine(line, MAXLINE);
	lowerString(line);
	if (len) {
		printf("The lower case string is:\n%s\n", line);
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


/* lower: convert a character to lowercase */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A'):(c);
}


/* lowerString: convert a string to lowercase */
void lowerString(char s[])
{
	int i = 0;
	while (s[i] != '\0') {
		s[i] = lower(s[i]);
		++i;
	}
}