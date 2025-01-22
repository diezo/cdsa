#include <stdio.h>
#include <stdlib.h>

struct Node;
struct Queue;

void init(struct Queue*);
int enqueue(struct Queue*, int);
int peek(struct Queue*);
int dequeue(struct Queue*);
int size(struct Queue *queue);
int isEmpty(struct Queue *queue);
void clear(struct Queue *queue);
int contains(struct Queue *queue, int target);

struct Node
{
	int val;

	struct Node* next;
	struct Node* prev;
};

struct Queue
{
	struct Node* front;
	struct Node* rear;
};

void init(struct Queue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

int enqueue(struct Queue *queue, int val)
{
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));

	// Memory Full
	if (node == NULL)
	{
		puts("Not enough memory.");
		return -1;
	}

	node->val = val;
	node->next = NULL;

	// Queue is Empty
	if (queue->rear == NULL)
	{
		// It's The First Node
		node->prev = NULL;

		queue->front = node;
		queue->rear = node;
	}

	// Queue isn't Empty
	else
	{
		// It Has a Previous Node
		node->prev = queue->front;

		queue->front->next = node;
		queue->front = node;
	}

	return val;
}

int peek(struct Queue *queue)
{
	// Queue is Empty?
	if (queue->rear == NULL)
	{
		puts("Queue Underflow!");
		exit(0);
	}

	return queue->rear->val;
}

int dequeue(struct Queue *queue)
{
	int val;
	struct Node *rearNode;

	// Queue is Empty?
	if (queue->rear == NULL)
	{
		puts("Queue Underflow!");
		exit(0);
	}

	rearNode = queue->rear;
	val = rearNode->val;

	if (queue->rear->next == NULL)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
	{
		struct Node *nextNode = queue->rear->next;

		nextNode->prev = NULL;
		queue->rear = nextNode;
	}

	free(rearNode);
	return val;
}

int size(struct Queue *queue)
{
	int n = 0;
	struct Node *node = queue->rear;

	while (node != NULL)
	{
		node = node->next;
		n++;
	}

	return n;
}

int isEmpty(struct Queue *queue)
{
	return size(queue) <= 0;
}

void clear(struct Queue *queue)
{
	struct Node *node = queue->rear;

	while (node != NULL)
	{
		struct Node *temp = node;
		node = node->next;

		free(temp);
	}

	queue->front = NULL;
	queue->rear = NULL;
}

int contains(struct Queue *queue, int target)
{
	int result = 0;
	struct Node *node = queue->rear;

	while (node != NULL)
	{
		if (node->val == target)
		{
			result = 1;
			break;
		}

		node = node->next;
	}

	return result;
}

int main()
{
	struct Queue queue;
	init(&queue);

	printf("Enqueued: %d\n", enqueue(&queue, 10));
	printf("Enqueued: %d\n", enqueue(&queue, 20));
	printf("Enqueued: %d\n", enqueue(&queue, 30));

	printf("Contains: %s\n", contains(&queue, 10) ? "Yes" : "No");
	printf("Size: %d\n", size(&queue));

	printf("Dequeued: %d\n", dequeue(&queue));
	printf("Dequeued: %d\n", dequeue(&queue));
	printf("Dequeued: %d\n", dequeue(&queue));
	
	printf("Size: %d\n", size(&queue));
	printf("Is Empty? %s\n", isEmpty(&queue) ? "Yes" : "No");

	clear(&queue);

	return 0;
}
