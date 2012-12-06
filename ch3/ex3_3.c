#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
void expand(char from[], char to[]);

/* expand shorthand notations */
int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	char expandedLine[MAXLINE];	/* longest line saved here */
	
	while ((len = getLine(line, MAXLINE)) > 0) {
		if (len > 0) {
			expand(line, expandedLine);
			printf("%s", expandedLine);
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


/* expand: expand shorthand notations like ... */
void expand(char from[], char to[])
{
	int i, j;
	
	i = j = 0;
	while (from[i] != '\0') {
		if ((from[i] == '.' && from[i+1] == '.' && from[i+2] == '.') && i && isalnum(from[i-1]) && isalnum(from[i+3])) {
			if (isalpha(from[i-1]) && isalpha(from[i+3]) && islower(from[i-1]) && islower(from[i+3])) {
				int c;
				c = from[i-1];
				while (c < from[i+3]) {
					to[j++] = ++c;
				}
				i += 4;
			} else if (isalpha(from[i-1]) && isalpha(from[i+3]) && isupper(from[i-1]) && isupper(from[i+3])) {
				int c;
				c = from[i-1];
				while (c < from[i+3]) {
					to[j++] = ++c;
				}
				i += 4;
			} else if (isdigit(from[i-1]) && isdigit(from[i+3])) {
				int c;
				c = from[i-1];
				while (c != from[i+3]) {
					if (from[i-1] < from[i+3])
						to[j++] = ++c;
					else
						to[j++] = --c;
				}
				i+=4;				
			} else {
				to[j++] = from[i++];
				continue;
			}
		} else if (from[i] == '-' && i && isalnum(from[i-1]) && isalnum(from[i+1])) {
			if (isalpha(from[i-1]) && isalpha(from[i+1]) && islower(from[i-1]) && islower(from[i+1])) {
				int c;
				c = from[i-1];
				while (c < from[i+1]) {
					to[j++] = ++c;
				}
				i += 2;
			} else if (isalpha(from[i-1]) && isalpha(from[i+1]) && isupper(from[i-1]) && isupper(from[i+1])) {
				int c;
				c = from[i-1];
				while (c < from[i+1]) {
					to[j++] = ++c;
				}
				i += 2;
			} else if (isdigit(from[i-1]) && isdigit(from[i+1])) {
				int c;
				c = from[i-1];
				while (c != from[i+1]) {
					if (from[i-1] < from[i+1])
						to[j++] = ++c;
					else
						to[j++] = --c;
				}
				i +=2;				
			} else {
				to[j++] = from[i++];
				continue;
			}
		} else {
			to[j++] = from[i++];
		}
	}
	to[j] = '\0';
}