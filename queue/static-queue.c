#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXITEMS 100

struct Queue;
void init(struct Queue*);
int enqueue(struct Queue*, int);
int dequeue(struct Queue*);
int size(struct Queue*);
bool isEmpty(struct Queue*);

struct Queue
{
	int items[MAXITEMS];
	int n;
};

void init(struct Queue *queue)
{
	queue->n = 0;
}

int enqueue(struct Queue *queue, int val)
{
	// Queue Overflow?
	if (queue->n >= MAXITEMS)
	{
		puts("Queue overflow!");
		exit(0);
	}

	// Append Item
	queue->items[queue->n] = val;

	// Increment Pointer
	(queue->n)++;

	return val;
}

int dequeue(struct Queue *queue)
{
	int val;

	// Queue Underflow?
	if (queue->n <= 0)
	{
		puts("Queue underflow!");
		exit(0);
	}

	val = queue->items[0];  // Get First Item
	
	// Shifting Required?
	if (queue->n > 1)
	{
		for (int i = 1; i < queue->n; i++) queue->items[i - 1] = queue->items[i];
	}

	(queue->n)--;  // Decrement Pointer

	return val;
}

int peek(struct Queue *queue)
{
	// Queue Underflow?
	if (queue->n <= 0)
	{
		puts("Queue underflow!");
		exit(0);
	}

	return queue->items[0];
}

int size(struct Queue *queue)
{
	return queue->n;
}

bool isEmpty(struct Queue *queue)
{
	return queue->n <= 0;
}

int main()
{
	struct Queue queue;
	init(&queue);

	printf("Enqueued: %d\n", enqueue(&queue, 10));
	printf("Enqueued: %d\n", enqueue(&queue, 20));
	
	printf("Dequeued: %d\n", dequeue(&queue));
	printf("Dequeued: %d\n", dequeue(&queue));

	printf("Size: %d\n", size(&queue));
	printf("Is Empty? %s\n", isEmpty(&queue) ? "Yes" : "No");
	
	return 0;
}
