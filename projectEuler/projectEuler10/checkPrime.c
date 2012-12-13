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
	while (conductor && ((long)conductor->object) <= ((long)sqrt(number)) ) {
		if ((number)%((long)conductor->object) == 0) {
			flag = 0;
			return flag;
		}
		conductor = conductor->next;		
	}
	
	if (flag && number > 1) {
		enlist(LinkedList, (void *)number);
	} else {
			return (flag = 0);
	}
	
	return flag;
}