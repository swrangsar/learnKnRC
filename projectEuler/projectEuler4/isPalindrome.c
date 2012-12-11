#include <stdio.h>
#include <stdlib.h>
#include "isPalindrome.h"
#define NUMSIZE 20	/* maximum length of the number */

int isPalindrome(int number)
{
	int original;
	original = number;
	char digits[NUMSIZE], *s;
	s = digits;
	do {
		*s++ = (number%10) + '0';
		number /= 10;
	} while (number);
	*s = '\0';
	
	if (atoi(digits) == original)
		return 1;
	else
		return 0;	
}