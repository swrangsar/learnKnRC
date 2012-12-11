#include <stdio.h>
#include "checkPrime.h"

#define NUMBER 600851475143L

int main()
{
	long number;
	number = NUMBER;
	
	long num, maxPrime;
	maxPrime = 0;
	num = 1;
	linkedList *primeList;
	primeList = createLinkedList();
	enlist(primeList, 2);
	while (num <= number) {
		if (checkPrime(primeList, num) && num > maxPrime) {
			maxPrime = num;
			printf("%ld\n", maxPrime);
			if (number%maxPrime == 0) {
				number /= maxPrime;
			}
		}
		num += 2;
	}
	
	printf("The largest prime factor is: %ld\n", maxPrime);
	printf("destroying linked list...\n");
	destroyLinkedList(primeList);
	return 0;
}