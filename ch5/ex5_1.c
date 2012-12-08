#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int main()
{
	int n, array[SIZE], getint(int *);
	
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	
	for (n = 0; n < SIZE; n++) {
		printf("%d. %d\n", n+1, array[n]);
	}
	
	return 0;
}

int getch(void);
void ungetch(int);

/* getint: get next intger from input into *pn */
int getint(int *pn)
{
	int c, sign;
	
	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1:1;
	if (c == '+' || c == '-')
		c = getch();
	if (isdigit(c)) {
		for (*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0');
		*pn *= sign;
	} else {
		*pn = 0;
	}
	if (c != EOF)
		ungetch(c);
	return c;
}

char buf;	/* buffer for ungetch */
int bufp = 0;
int getch(void)	/* get a (possibly pushed-back) character */
{
	if (bufp) {
		bufp = 0;
		return buf;
	} else {
		return getchar();		
	}
}

void ungetch(int c) 	/* push character back on input */
{
	buf = c;
	bufp = 1;
}