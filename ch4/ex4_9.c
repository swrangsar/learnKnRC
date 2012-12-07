#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */

int getop(char s[]);
void push(double);
double pop(void);
void printTop2(void);
void duplicate(void);
void swapTop2(void);

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	double recentlyPrintedValue = 0.0;
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
					op2 = pop();
					if (op2 != 0.0)
						push((int)pop() % (int)  op2);
					else
						printf("error: zero divisor\n");
					break;
			case '\n':
				printf("\t%.8g\n", (recentlyPrintedValue = pop() ));
				break;
			case 'T':
				printTop2();
				break;
			case 'D':
				duplicate();
				break;
			case 'S':
				swapTop2();
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case 'r':
				printf("\t%.8g\n", recentlyPrintedValue);
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}


#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;	/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* printTop2: print top two elements */
void printTop2(void)
{
	int k;
	k = sp;
	if (k > 1) {
		printf("Top: %f Nexttop: %f\n", val[k-1], val[k-2]);
	} else if (k > 0) {
		printf("Top: %f Nexttop: DNE\n", val[k-1]);
	} else {
		printf("Stack empty: can't print top 2 elements!\n");
	}
}

/* duplicate: duplicate the top stack element */
void duplicate(void)
{
	if (sp > 0 && sp < MAXVAL) {
		val[sp] = val[sp-1];
		++sp;
	} else {
		printf("Stack empty: can't duplicate!\n");
	}
}

/* swapTop2: swap top 2 elements of stack */
void swapTop2(void)
{
	if (sp > 1) {
		double temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
	} else {
		printf("Not enough elements to swap!\n");
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	/* not a number */
	else {
		if (c == '-') {
			if (!isdigit(c = getch())) {
				ungetch(c);
				return '-';
			} else {
				ungetch(c);
			}
		}
	}
	i = 0;
	if (isdigit(c))	/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}



int buf;	/* buffer for ungetch */
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