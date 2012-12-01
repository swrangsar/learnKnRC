#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */
#define TABSTOP 8
#define FOLDLENGTH 20	/* maximum length after fold */

int getLine(char line[], int maxline);
void foldline(char to[], char from[]);


/* print the longest input line */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			foldline(longest, line);
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


/* foldline: fold lines longer than some fixed length */
void foldline(char to[], char from[])
{
	int i, j;
	i = j = 0;
	while (from[i] != '\0') {
		if (((i+1) % FOLDLENGTH) == 1 && (i != 0) && (from[i] != '\n')) {
			to[j] = ' ';
			to[++j] = '\\';
			to[++j] = '\n';
			to[++j] = '\t';
			to[++j] = from[i];
			++j;
		} else {
			to[j] = from[i];
			++j;
		}
		++i;
	}
	to[j] = '\0';
}