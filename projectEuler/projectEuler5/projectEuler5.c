#include <stdio.h>
#include "linkedList.h"
#define LIMIT 20

long getExtraFactor(linkedList *LinkedList, long number);

int main()
{
	linkedList *LinkedList;
	LinkedList = createLinkedList();
	long i, product;
	i = 0;
	product = 1;
	while (++i <= LIMIT) {
		product *= getExtraFactor(LinkedList, i);
	}

	printf("The product is: %ld\n", product);
	return 0;
}

long getExtraFactor(linkedList *LinkedList, long number)
{
	linkedListNode *conductor;
	conductor = LinkedList->head;
	while (conductor) {
		if (number % conductor->prime == 0)
			number /= conductor->prime;
		conductor = conductor->next;
	}
	if (number > 1)
		enlist(LinkedList, number);
	return number;
}