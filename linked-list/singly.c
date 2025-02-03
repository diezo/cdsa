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
	node->next = NULL;

	if (linkedList->head == NULL)
	{
		linkedList->head = node;
		linkedList->tail = node;

		return;
	}

	struct Node *prevNode = linkedList->head;
	
	while (prevNode->next != NULL)
	{
		prevNode = prevNode->next;
	}

	prevNode->next = node;
	linkedList->tail = node;
}

void show(struct LinkedList *linkedList)
{
	struct Node *node = linkedList->head;

	while (node != NULL)
	{
		printf("%d\n", node->val);
		node = node->next;
	}
}

int find(struct LinkedList *linkedList, int target)
{
	int i = 0;
	struct Node *node = linkedList->head;

	while (node != NULL)
	{
		if (node->val == target) return i;
		
		node = node->next;
		i++;
	}

	return -1;
}

int pop(struct LinkedList *linkedList, int index)
{
	if (index < 0) return 0;  // Should Return NULL

	int i = 0;
	struct Node *prevNode = NULL;
	struct Node *node = linkedList->head;
	int val = 0;  // Should Be NULL

	while (node != NULL)
	{
		if (i == index) break;
		
		prevNode = node;
		node = node->next;
		i++;
	}

	if (node != NULL)
	{
		struct Node *nextNode = node->next;

		if (prevNode != NULL)
		{
			prevNode->next = nextNode;
			if (nextNode == NULL) linkedList->tail = prevNode;
		}
		else
		{
			linkedList->head = node->next;
			if (nextNode == NULL) linkedList->tail = NULL;
		}

		val = node->val;
		free(node);
	}

	return val;
}

int delete(struct LinkedList *linkedList, int val)
{
	int i = 0;
	struct Node *prevNode = NULL;
	struct Node *node = linkedList->head;

	while (node != NULL)
	{
		if (node->val == val) break;

		prevNode = node;
		node = node->next;
		i++;
	}

	if (node != NULL)
	{
		struct Node *nextNode = node->next;

		if (prevNode != NULL)
		{
			prevNode->next = nextNode;
			if (nextNode == NULL) linkedList->tail = prevNode;
		}
		else
		{
			linkedList->head = node->next;
			if (nextNode == NULL) linkedList->tail = NULL;
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
	
	add(&linkedList, 1);
	add(&linkedList, 2);
	add(&linkedList, 3);
	add(&linkedList, 4);
	add(&linkedList, 5);

	show(&linkedList);

	return 1;
}
