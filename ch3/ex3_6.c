#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void reverse(char s[]);
void itoa(int n, char s[], int minFieldWidth);

/* expand shorthand notations */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	char expandedLine[MAXLINE];	/* longest line saved here */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			itoa(atoi(line), expandedLine, 8);
			printf("%s\n", expandedLine);
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
void reverse(char s[])
{
	int c, i, j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[], int minFieldWidth)
{
	int i, sign, flag;
	flag = 0;
	if ((sign = n) < 0) {
		if (n == INT_MIN) {
			n = -(n + 1);
			flag = 1;
		} else {
			n = -n;
		}
	}
	
	i = 0;
	do {
		s[i++] = n%10 + '0';
	} while ((n /= 10) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	while (i < minFieldWidth) {
		s[i++] = ' ';
	}
	s[i] = '\0';
	
	int carry = 1;
	if (flag) {
		int k = 0;
		
		while (carry == 1 && s[k] != '-') {
			if ((s[k]-'0' + 1) > 9) {
				carry = 1;
				s[k] = '0';
			} else {
				s[k] += 1;
				carry = 0;
			}
			++k;
		}
		if (carry  == 1 && (s[k] == '-')) {
			s[k++] = 1 + '0';
			s[k++] = '-';
			while (k < minFieldWidth) {
				s[k++] = ' ';
			}
			s[k++] = '\0';
		}
	}
	
	reverse(s);
}