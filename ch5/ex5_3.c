#include <stdio.h>
#define MAXLINE 100	/* maximum input line length */

int getLine(char line[], int maxline);
void strCat(char *s, char *t);


int main()
{
	int len1, len2;	/* current line length */
	char line1[MAXLINE];
	char line2[MAXLINE];
	
	len1 = getLine(line1, MAXLINE);
	len2 = getLine(line2, MAXLINE);
	
	if (len1 && len2) {
		strCat(line1, line2);
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


/* strcat: concatenate t to s */
void strCat(char *s, char *t)
{
	while (*s != '\0' && *s != '\n')
		s++;
	while ((*s++ = *t++) != '\0')
		;
}