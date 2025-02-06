#include <stdio.h>
#include <stdlib.h>

struct Node;
struct Stack;

void init(struct Stack*);
void push(struct Stack*, int val);
void display(struct Stack*);
int peek(struct Stack*);
int pop(struct Stack*);
int multipop(struct Stack*, int);
int size(struct Stack*);
int isEmpty(struct Stack*);

struct Node
{
	int val;

	struct Node *prev;
	struct Node *next;
};

struct Stack
{
	struct Node *front;
	struct Node *rear;
};

void init(struct Stack *stack)
{
	stack->front = NULL;
	stack->rear = NULL;
}

void push(struct Stack *stack, int val)
{
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	node->val = val;

	node->next = NULL;

	if (stack->rear == NULL)
	{
		node->prev = NULL;
		
		stack->front = node;
		stack->rear = node;

		return;
	}

	stack->rear->next = node;
	node->prev = stack->rear;

	stack->rear = node;
}

void display(struct Stack *stack)
{
	if (stack->rear == NULL) return;

	int i = 1;
	struct Node *node = stack->front;

	while (node != NULL)
	{
		printf("[%d] Node: %d\n", i, node->val);

		node = node->next;
		i++;
	}
}

int peek(struct Stack *stack)
{
	if (stack->rear == NULL)
	{
		puts("Stack underflow!");
		return -1;
	}

	return stack->rear->val;
}

int pop(struct Stack *stack)
{
	struct Node *node;
	int val;
	struct Node *nodePrev;

	if (stack->rear == NULL)
	{
		puts("Stack underflow!");
		return -1;
	}

	node = stack->rear;
	nodePrev = stack->rear->prev;
	
	val = node->val;

	if (nodePrev == NULL)
	{
		stack->front = NULL;
		stack->rear = NULL;
	}
	else
	{
		nodePrev->next = NULL;
		stack->rear = nodePrev;
	}

	free(node);

	return val;
}

int multipop(struct Stack *stack, int n)
{
	int val;

	for (int i = 0; i < n; i++)
	{
		val = pop(stack);
	}

	return val;
}

int size(struct Stack *stack)
{
	int n = 0;

	if (stack->rear == NULL) return 0;

	struct Node *node = stack->front;

	while (node != NULL)
	{
		node = node->next;
		n++;
	}

	return n;
}

int isEmpty(struct Stack *stack)
{
	return size(stack) < 1;
}

int main()
{
	struct Stack stack;
	init(&stack);

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	display(&stack);

	printf("Size: %d\n", size(&stack));

	//printf("Popped: %d\n", pop(&stack));
	//printf("Popped: %d\n", pop(&stack));
	//printf("Popped: %d\n", pop(&stack));
	
	printf("Peeked: %d\n", peek(&stack));
	printf("Peeked: %d\n", peek(&stack));
	printf("Peeked: %d\n", peek(&stack));

	printf("Multipopped (2): %d\n", multipop(&stack, 2));

	printf("Size: %d\n", size(&stack));
	
	display(&stack);

	return 0;
}
