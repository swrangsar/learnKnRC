#include <stdio.h>
#include "isPalindrome.h"
#define LIMIT 1000

int main()
{
	int i, j, maxPalindrome;
	i = j = 0;
	maxPalindrome = 0;
	
	while (++i < LIMIT) {
		j = 0;
		while (++j < LIMIT) {
			if (isPalindrome(i*j) && (i * j) > maxPalindrome)
				maxPalindrome = i*j;
		}
	}
	
	printf("The largest palindrome is: %d\n", maxPalindrome);
	return 0;
}