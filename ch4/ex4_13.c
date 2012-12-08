#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void reverse(char s[], int left, int right);


int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	int left, right;
	left = 0;
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			right = len-1;
			reverse(line, left, right);
			printf("%s\n", line);
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


/* reverse: reverse string s in place */
void reverse(char s[], int left, int right)
{
	int temp;
	temp = s[right];
	s[right] = s[left];
	s[left] = temp;
	if (++left < --right) {
		reverse(s, left, right);
	}
}