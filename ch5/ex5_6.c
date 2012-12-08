#include <stdio.h>

#define MAXLINE 100		/* maximum input line length */

int getLine(char *line, int maxline);

int main()
{
	char line[MAXLINE];
	
	while (getLine(line, MAXLINE))
		printf("Line: %s", line);
		
	return 0;
}


/* getline: read a line into s, return length */
int getLine(char *s, int lim)
{
	int c, i;
	
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		*s++ = c;
	if (c == '\n') {
		*s++ = c;
		++i;
	}
	*s = '\0';
	
	return i;
}