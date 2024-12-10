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
	node->next = linkedList->head;

	if (linkedList->head == NULL)
	{
		linkedList->head = node;
		linkedList->tail = node;

		return;
	}

	struct Node *prevNode = linkedList->head;
	
	while (prevNode != linkedList->tail)
	{
		prevNode = prevNode->next;
	}

	prevNode->next = node;
	linkedList->tail = node;
}

void show(struct LinkedList *linkedList)
{
	if (linkedList->head == NULL) return;

	struct Node *node = linkedList->head;

	do
	{
		printf("%d\n", node->val);
		node = node->next;
	}
	while (node != linkedList->head);
}

int find(struct LinkedList *linkedList, int target)
{
	if (linkedList->head == NULL) return -1;

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
	if (linkedList->head == NULL || index < 0) return 0;  // Should Return NULL

	int i = 0;
	int found = 0;
	struct Node *prevNode = NULL;
	struct Node *node = linkedList->head;
	int val = 0;  // Should Be NULL

	do
	{
		if (i == index)
		{
			found++;
			break;
		}
		
		prevNode = node;
		node = node->next;
		i++;
	}
	while (node != linkedList->head);

	if (found)
	{
		struct Node *nextNode = node->next;

		if (prevNode != NULL)
		{
			if (nextNode != NULL) prevNode->next = nextNode;
			else
			{
				prevNode->next = linkedList->head;
				linkedList->tail = prevNode;
			}
		}
		else
		{
			if (nextNode != NULL)
			{
				linkedList->head = nextNode;
				linkedList->tail->next = nextNode;
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
	int found = 0;
	struct Node *prevNode = NULL;
	struct Node *node = linkedList->head;

	do
	{
		if (node->val == val)
		{
			found++;
			break;
		}

		prevNode = node;
		node = node->next;
		i++;
	}
	while (node != linkedList->head);

	if (found)
	{
		struct Node *nextNode = node->next;

		if (prevNode != NULL)
		{
			if (nextNode != NULL) prevNode->next = nextNode;
			else
			{
				prevNode->next = linkedList->head;
				linkedList->tail = prevNode;
			}
		}
		else
		{
			if (nextNode != NULL)
			{
				linkedList->head = nextNode;
				linkedList->tail->next = nextNode;
			}
			else
			{
				linkedList->head = NULL;
				linkedList->tail = NULL;
			}
		}

		free(node);
		return i;
	}

	return -1;
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
