#include <stdio.h>
#include <string.h>

#define MAXLINES 100	/* max #lines to be sorted */
#define MAXLEN 100		/* max length of any input line */

char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int maxlines, char *linesArray);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
	int nlines;		/* number of input lines read */
	char linesArray[MAXLINES * MAXLEN];

	
	if ((nlines = readlines(lineptr, MAXLINES, linesArray)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

int getLine(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *linesArray)
{
	int len, nlines;
	char *p, line[MAXLEN];
	p = linesArray;
	
	nlines = 0;
	while ((len = getLine(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p >= (linesArray + (MAXLINES * MAXLEN))))
			return -1;
		else {
			line[len-1] = '\0';	/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += MAXLEN;
		}
	return nlines;
}

/* getLine: read a line into s, return length */
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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right)	/* do nothing if array contains */
		return;			/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}