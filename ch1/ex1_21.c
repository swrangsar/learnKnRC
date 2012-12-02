#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */
#define TABSTOP 8


int getLine(char line[], int maxline);
void entab(char to[], char from[]);


/* print the longest input line */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			entab(longest, line);
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


/* entab: replace spaces with tabs wherever possible */
void entab(char to[], char from[])
{
	int i, j;
	i = j = 0;
	
	while (from[i] != '\0') {
		if (((i+1) % TABSTOP) == 0) {
			int k = 0;
			while (k < TABSTOP && from[i - k] == ' ') {
				++k;
			}
			int m = (i+1) - TABSTOP;
			while (m <= (i-k)) {
				to[j] = from[m];
				++j;
				++m;
			}
			if (k > 0) {
				to[j] = '$';
				++j;
			}
			
		}
		++i;
	}
	
	int remainlength;
	if ((remainlength = (i % TABSTOP)) != 0) {
		int k = i - remainlength;
		while (from[k] != '\0') {
			to[j] = from[k];
			++k;
			++j;
		}		
	}
	to[j] = '\0';
}