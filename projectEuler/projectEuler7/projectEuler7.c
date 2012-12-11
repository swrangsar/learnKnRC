#include <stdio.h>
#include "checkPrime.h"

#define LIMIT 10001

int main()
{
	int i;	
	long num, maxPrime;
	maxPrime = 0;
	i = 0;
	num = 1;
	linkedList *primeList;
	primeList = createLinkedList();
	enlist(primeList, 2);
	++i;
	while (i < LIMIT) {
		if (checkPrime(primeList, num) && num > maxPrime) {
			maxPrime = num;
			printf("%ld\n", maxPrime);
			++i;
		}
		num += 2;
	}
	
	printf("The reqd prime is: %ld\n", maxPrime);
	printf("destroying linked list...\n");
	destroyLinkedList(primeList);
	return 0;
}