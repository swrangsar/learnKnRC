#include <stdio.h>

#define INCOMMENT 0	/* inside a comment */
#define OUTCOMMENT 1	/* outside a comment */

int main()
{
	int c;
	int state;
	
	c = 0;
	state = OUTCOMMENT;
	
	while ((c = getchar()) != EOF) {
		if (state == OUTCOMMENT) {
			if (c == '/') {
				c = getchar();
				if (c == '*') {
					state = INCOMMENT;
				} else if (c == EOF) {
					putchar('/');
					break;
				} else {
					putchar('/');
					putchar(c);
				}
			} else {
				putchar(c);
			}
		} else {
			if (c == '*') {
				c = getchar();
				if (c == '/') {
					state = OUTCOMMENT;
				} else if (c == EOF) {
					break;
				} else {
					continue;
				}
			}
		}
	}
	
	return 0;
}