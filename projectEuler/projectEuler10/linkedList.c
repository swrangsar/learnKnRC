#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

linkedList *createLinkedList(void)
{
	linkedList *newLinkedList;
	newLinkedList = malloc(sizeof(linkedList));
	if (!newLinkedList) {
		printf("Linked list could not be allocated.\n");
		exit(1);
	}
	newLinkedList->head = NULL;
	newLinkedList->tail = NULL;
	return newLinkedList;
}

static linkedListNode *createLinkedListNode(long prime)
{
	linkedListNode *newLinkedListNode;
	newLinkedListNode = malloc(sizeof(linkedListNode));
	if (!newLinkedListNode) {
		printf("Linked list node could not be allocated.\n");
		exit(1);
	}
	newLinkedListNode->prime = prime;
	newLinkedListNode->prev = NULL;
	newLinkedListNode->next = NULL;
	return newLinkedListNode;
}

void enlist(linkedList *LinkedList, long prime)
{
	linkedListNode *newLinkedListNode;
	newLinkedListNode = createLinkedListNode(prime);
	newLinkedListNode->prev = LinkedList->tail;
	if (!LinkedList->head) {
		LinkedList->head = newLinkedListNode;
		LinkedList->tail = newLinkedListNode;
	} else if (LinkedList->tail) {
		LinkedList->tail->next = newLinkedListNode;
		LinkedList->tail = newLinkedListNode;
	} else {
		printf("Linked list tail can't be NULL.\n");
		exit(1);
	}
}

linkedListNode *delist(linkedList *LinkedList)
{
	linkedListNode *oldLinkedListNode;
	oldLinkedListNode = LinkedList->tail;
	if (oldLinkedListNode) {
		LinkedList->tail = LinkedList->tail->prev;
		if (LinkedList->tail) {
			LinkedList->tail->next = NULL;
		} else {
			LinkedList->head = NULL;			
		}
		free(oldLinkedListNode);
	}
	return LinkedList->tail;
}

void destroyLinkedList(linkedList *LinkedList)
{
	while (delist(LinkedList))
		;
	if (LinkedList)
		free(LinkedList);
}