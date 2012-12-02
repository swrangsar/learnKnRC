#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void squeezeChar(char s[], int c);
void squeeze(char s1[], char s2[]);


/* print the longest input line */
int main()
{
	int len1, len2;	/* current line length */
	char line1[MAXLINE], line2[MAXLINE];	/* current input line */
	
	len1 = getLine(line1, MAXLINE);
	len2 = getLine(line2, MAXLINE);
	
	if (len1 && len2) {
		squeeze(line1, line2);
		printf("%s\n", line1);
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

/* squeezeChar: squeeze a single character */
void squeezeChar(char s[], int c)
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; ++i)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

/* squeeze: squeeze s1 with characters in s2 */
void squeeze(char s1[], char s2[])
{
	int i = 0;
	while (s2[i] != '\0') {
		if (s2[i] != '\n') {
			squeezeChar(s1, s2[i]);
		}
		++i;
	}
}