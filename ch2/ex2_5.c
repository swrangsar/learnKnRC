#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
int anyChar(char s[], int c);
int any(char s1[], char s2[]);


/* print the longest input line */
int main()
{
	int len1, len2;	/* current line length */
	char line1[MAXLINE], line2[MAXLINE];	/* current input line */
	
	len1 = getLine(line1, MAXLINE);
	len2 = getLine(line2, MAXLINE);
	
	if (len1 && len2) {
		printf("The first matching index is: %d\n", any(line1, line2));
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


/* anyChar: find a character in the string */
int anyChar(char s[], int c)
{
	int i = 0;
	while (s[i] != '\0') {
		if (c == s[i])
			return 1;
		++i;
	}
	return 0;
}

/* any: get first index of s1 character present in s2 */
int any(char s1[], char s2[])
{
	int index = -1;
	int i = 0;
	
	while (s1[i] != '\0') {
		if (anyChar(s2, s1[i])) {
			index = i+1;
			break;
		}
		++i;
	}
	return index;
}