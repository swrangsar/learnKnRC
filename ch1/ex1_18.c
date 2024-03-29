#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int trimLine(char line[], int len);


/* print the longest input line */
int main()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	
	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			copy(longest, line);
			int newlen;
			newlen = trimLine(longest, len);
			if (newlen > 0)
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


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

/* clean up trailing blanks and tabs */

int trimLine(char line[], int len)
{
	int i = len-1;
	
	while (line[i] == ' ' || line[i] == '\t') {
		--i;
	}
	
	if (++i < len) {
		line[i] = '\n';
		line[++i] = '\0';
	}
	
	if (line[0] == '\n') {
		line[0] = '\0';
		i = 0;
	}
	
	return i;
}
