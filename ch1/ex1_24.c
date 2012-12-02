#include <stdio.h>

#define MAXPARENTHESES 100	/* maximum number of nesting levels */

int main()
{
	char parentheses[MAXPARENTHESES];	/* stack holding previous opening parentheses, etc. */
	char quote;	/* holding the previous quote */
	
	int top;	/* top of the parentheses stack */
	int c, prev;
	
	top = -1;
	c = prev = 0;
	quote = '\0';
	
	while ((c = getchar()) != EOF) {
		if (c == '(') {
			parentheses[++top] = '(';
		} else if (c == '[') {
			parentheses[++top] = '[';
		} else if (c == '{') {
			parentheses[++top] = '{';
		} else if (c == ')') {
			if (parentheses[top] != '(')
				break;
			else
				--top;
		} else if (c == ']') {
			if (parentheses[top] != '[')
				break;
			else
				--top;
		} else if (c == '}') {
			if (parentheses[top] != '{')
				break;
			else
				--top;
		} else if (c == '\'' && prev != '\\') {
			if (quote == '\0') {
				quote = '\'';
			} else if (quote == '\'') {
				quote = '\0';
			} else {
				/* do nothing */
			}
		} else if (c == '\"' && prev != '\\') {
			if (quote == '\0') {
				quote = '\"';
			} else if (quote == '\"') {
				quote = '\0';
			} else {
				/* do nothing */
			}
		}
		putchar(c);
		prev = c;
	}
	
	if (quote != '\0') {
		printf("\nError: A %c quote was not closed!\n", quote);
	}
	
	return 0;
}