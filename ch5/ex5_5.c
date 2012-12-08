#include <stdio.h>

#define MAXLINE 100	/* maximum input line length */
#define NUM 10

int getLine(char line[], int maxline);
char *strncpy(char *s, char *t, int n);
char *strncat(char *s, char *t, int n);
int strnCmp(char *s, char *t, int n);

int main()
{
	int len1, len2;	/* current line length */
	char line1[MAXLINE];
	char line2[MAXLINE];
	
	len1 = getLine(line1, MAXLINE);
	len2 = getLine(line2, MAXLINE);
	
	if (len1 && len2) {
		printf("Result: %s\n", strncpy(line1, line2, NUM));
	}
	
	len1 = getLine(line1, MAXLINE);
	len2 = getLine(line2, MAXLINE);
	
	if (len1 && len2) {
		printf("Result: %s\n", strncat(line1, line2, NUM));
	}
	
	len1 = getLine(line1, MAXLINE);
	len2 = getLine(line2, MAXLINE);
	
	if (len1 && len2) {
		printf("Difference: %d\n", strnCmp(line1, line2, NUM));
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

/* strncpy: copy at n characters from t to s */
char *strncpy(char *s, char *t, int n)
{
	char *s1;
	s1 = s;
	while (n-- && (*s++ = *t++))
		;
	*s = '\0';
	return s1;
}

/* strncat: concatenate not more than n characters */
char *strncat(char *s, char *t, int n)
{
	char *s1;
	s1 = s;
	while (*s)
		s++;
	while (n-- && (*s++ = *t++))
		;
	*s = '\0';
	return s1;
}

/* strncmp: compare not more than n characters */
int strnCmp(char *s, char *t, int n)
{
	while (n-- && *s++ == *t++)
		if (*(s-1) == '\0')
			return 0;
	return *--s - *--t;
}