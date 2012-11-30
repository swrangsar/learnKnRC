#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */
#define TABSTOP 8


int getLine(char line[], int maxline);
void detab(char to[], char from[]);


/* print the longest input line */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			detab(longest, line);
			printf("%s", longest);
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


/* detab: replace tabs with appropriate number of spaces */
void detab(char to[], char from[])
{
	int i, j;
	int tabposition;
	i = j = 0;
	
	while (from[i] != '\0') {
		if (from[i] == '\t') {
			tabposition = j % TABSTOP;
			if (tabposition == 0) {
				int k = 0;
				while (k < TABSTOP) {
					to[j] = ' ';
					++j;
					++k;
				}
			} else {
				int k = 0;
				while (k < (TABSTOP - tabposition)) {
					to[j] = ' ';
					++j;
					++k;
				}
			}
		} else {
			to[j] = from[i];
			++j;
		}
		++i;
	}
	to[j] = '\0';
}