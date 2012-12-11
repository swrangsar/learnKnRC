#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct linkedListNode {
	long prime;
	struct linkedListNode *prev;
	struct linkedListNode *next;
} linkedListNode;

typedef struct linkedList {
	linkedListNode *head;
	linkedListNode *tail;
} linkedList;

linkedList *createLinkedList(void);
static linkedListNode *createLinkedListNode(long prime);
void enlist(linkedList *LinkedList, long prime);
linkedListNode *delist(linkedList *LinkedList);
void destroyLinkedList(linkedList *LinkedList);

#endif




