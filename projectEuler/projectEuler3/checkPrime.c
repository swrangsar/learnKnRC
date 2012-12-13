#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "checkPrime.h"

int checkPrime(linkedList *LinkedList, long number)
{
	int flag;
	flag = 1;
	linkedListNode *conductor;
	conductor = LinkedList->head;
	while (conductor && (conductor->prime <= ((long)sqrt(number)))) {
		if ((number)%(conductor->prime) == 0) {
			flag = 0;
			return flag;
		}
		conductor = conductor->next;		
	}
	
	if (flag && number > 1) {
		enlist(LinkedList, number);
	} else {
			return (flag = 0);
	}
	
	return flag;
}