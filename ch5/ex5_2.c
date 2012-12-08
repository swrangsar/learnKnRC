#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int main()
{
	int n, getfloat(float *);
	float array[SIZE];
	
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;
	
	for (n = 0; n < SIZE; n++) {
		printf("%d. %f\n", n+1, array[n]);
	}
	
	return 0;
}

int getch(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
	int c, sign;
	
	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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
	if (c == '.') {
		if (isdigit(c = getch())) {
			float mantissa, power;
			for (mantissa=0, power = 1; isdigit(c); c = getch(), power *= 10)
				mantissa = 10 * mantissa + (c - '0');
			mantissa /= power;
			*pn += (mantissa *sign);
		} else {
			*pn = 0;
		}
	}
	if (c != EOF)
		ungetch(c);
	return c;
}


#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;	/* next free position in buf */

int getch(void)	/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp]:getchar();
}

void ungetch(int c) 	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
	int i = 0;
	while (bufp < BUFSIZE && s[i] != '\0') {
		buf[bufp++] = s[i++];
	}
}
