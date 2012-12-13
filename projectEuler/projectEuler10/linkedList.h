#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct linkedListNode {
	void *object;
	struct linkedListNode *prev;
	struct linkedListNode *next;
} linkedListNode;

typedef struct linkedList {
	linkedListNode *head;
	linkedListNode *tail;
} linkedList;

linkedList *createLinkedList(void);
void enlist(linkedList *LinkedList, void *object);
linkedListNode *delist(linkedList *LinkedList);
void destroyLinkedList(linkedList *LinkedList);

#endif