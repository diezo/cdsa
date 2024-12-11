#include <stdio.h>
#include <stdlib.h>

struct Node;
struct LinkedList;
void init(struct LinkedList*);
void add(struct LinkedList*, int);
void show(struct LinkedList*);
int find(struct LinkedList*, int);
int pop(struct LinkedList*, int);
int delete(struct LinkedList*, int);
int update(struct LinkedList*, int, int);

struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
};

struct LinkedList
{
	struct Node *head;
	struct Node *tail;
};

void init(struct LinkedList *linkedList)
{
	linkedList->head = NULL;
	linkedList->tail = NULL;
}

void add(struct LinkedList *linkedList, int val)
{
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));

	node->val = val;
	node->prev = linkedList->tail;
	node->next = linkedList->head;

	if (linkedList->head == NULL)
	{
		node->prev = node;
		node->next = node;

		linkedList->head = node;
		linkedList->tail = node;

		return;
	}

	struct Node *prevNode = linkedList->tail;

	prevNode->next = node;
	linkedList->tail = node;
	linkedList->head->prev = node;
}

void show(struct LinkedList *linkedList)
{
	if (linkedList->head == NULL) return;

	struct Node *node = linkedList->head;

	do
	{
		printf("%d (Prev: %d; Next: %d)\n", node->val, node->prev->val, node->next->val);
		node = node->next;
	}
	while (node != linkedList->head);
}

int find(struct LinkedList *linkedList, int target)
{
	int i = 0;
	struct Node *node = linkedList->head;

	do
	{
		if (node->val == target) return i;
		
		node = node->next;
		i++;
	}
	while (node != linkedList->head);

	return -1;
}

int pop(struct LinkedList *linkedList, int index)
{
	int i = 0;
	struct Node *headNode = linkedList->head;
	struct Node *tailNode = linkedList->tail;

	if (headNode == NULL || index < 0) return 0;  // Should Return NULL

	int found = 0;
	struct Node *node = linkedList->head;
	int val = 0;  // Should Be NULL

	do
	{
		if (i == index)
		{
			found++;
			break;
		}
		
		node = node->next;
		i++;
	}
	while (node != linkedList->head);

	if (found)
	{
		struct Node *headNode = linkedList->head;
		struct Node *tailNode = linkedList->tail;

		struct Node *prevNode = node->prev;
		struct Node *nextNode = node->next;

		if (prevNode != NULL && prevNode != tailNode)
		{
			prevNode->next = (nextNode == NULL) ? headNode : nextNode;

			if (nextNode != NULL) nextNode->prev = prevNode;
			else
			{
				linkedList->tail = prevNode;
				headNode->prev = prevNode;
			}
		}
		else
		{
			if (nextNode != NULL && nextNode != headNode)
			{
				linkedList->head = nextNode;

				tailNode->next = nextNode;
				nextNode->prev = tailNode;
			}
			else
			{
				linkedList->head = NULL;
				linkedList->tail = NULL;
			}
		}

		val = node->val;
		free(node);
	}

	return val;
}

int delete(struct LinkedList *linkedList, int val)
{
	int i = 0;
	struct Node *headNode = linkedList->head;
	struct Node *tailNode = linkedList->tail;

	if (headNode == NULL) return i;

	int found = 0;
	struct Node *node = linkedList->head;

	do
	{
		if (node->val == val)
		{
			found++;
			break;
		}

		node = node->next;
		i++;
	}
	while (node != linkedList->head);

	if (found)
	{
		struct Node *prevNode = node->prev;
		struct Node *nextNode = node->next;

		if (prevNode != NULL && prevNode != tailNode)
		{
			prevNode->next = (nextNode == NULL) ? headNode : nextNode;

			if (nextNode != NULL) nextNode->prev = prevNode;
			else
			{
				linkedList->tail = prevNode;
				headNode->prev = prevNode;
			}
		}
		else
		{
			if (nextNode != NULL && nextNode != headNode)
			{
				linkedList->head = nextNode;

				tailNode->next = nextNode;
				nextNode->prev = tailNode;
			}
			else
			{
				linkedList->head = NULL;
				linkedList->tail = NULL;
			}
		}

		free(node);
	}

	return i;
}

int update(struct LinkedList *linkedList, int index, int newVal)
{
	if (index < 0) return 0;  // Should Return Null

	int i = 0;
	int val = 0;  // Should Be NULL
	struct Node *node = linkedList->head;

	while (node != NULL)
	{
		if (i == index)
		{
			val = node->val;
			node->val = newVal;

			break;
		}

		node = node->next;
		i++;
	}

	return val;
}

int main()
{
	struct LinkedList linkedList;
	init(&linkedList);

	add(&linkedList, 100);
	add(&linkedList, 200);
	add(&linkedList, 300);
	add(&linkedList, 400);
	add(&linkedList, 500);

	show(&linkedList);

	return 1;
}
