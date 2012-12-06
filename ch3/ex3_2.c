#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void escape(char to[], char from[]);

/* escape blank characters */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	char escapedLine[MAXLINE];	/* longest line saved here */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			escape(escapedLine, line);
			printf("%s\n", escapedLine);
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


/* escape: escape blank characters in line while copying */
void escape(char to[], char from[])
{
	int i, j;
	
	i = j = 0;
	while (from[i] != '\0') {
		switch(from[i]) {
			case '\n':
				to[j++] = '\\';
				to[j++] = 'n';
				break;
			case '\t':
				to[j++] = '\\';
				to[j++] = 't';
				break;
			default:
				to[j++] = from[i];
				break;			
		}
		++i;
	}
	to[j] = '\0';
}