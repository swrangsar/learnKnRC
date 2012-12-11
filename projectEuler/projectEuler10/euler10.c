#include <stdio.h>
#include "checkPrime.h"

#define NUMBER 2000000L

int main()
{
	long sum, num, maxPrime;

	sum = 2;	
	maxPrime = 0;
	num = 1;
	linkedList *primeList;
	primeList = createLinkedList();
	enlist(primeList, 2);
	while (num < NUMBER) {
		if (checkPrime(primeList, num) && num > maxPrime) {
			maxPrime = num;
			printf("%ld\n", maxPrime);
			sum += maxPrime;
		}
		num += 2;
	}
	
	printf("The largest prime factor is: %ld\n", maxPrime);
	printf("destroying linked list...\n");
	printf("The sum is: %ld\n", sum);
	destroyLinkedList(primeList);
	return 0;
}