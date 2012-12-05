#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int maxline);
int binsearch(int x, int v[], int n);


int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */
	int v[100];
	
	int i;
	for (i = 0; i < 100; ++i) {
		v[i] = (i + 1) * 5;
	}
	
	len = getLine(line, MAXLINE);
	
	if (len) {
		printf("The matching index is: %d\n", binsearch(atoi(line), v, i));
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


/* binsearch: find x in v[] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	
	while (low <= high) {
		mid = (low + high)/2;
		if (x < v[mid]) {
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	
	if (x == v[mid]) {
		return mid;
	} else {
		return -1;
	}
}
