#include <stdio.h>

#define STACK_MAX 100

typedef struct
{
	int items[STACK_MAX];
	int top;
} Stack;

int isEmpty(Stack*);
int isFull(Stack*);
int init(Stack*);
void push(Stack*, int);
void show(Stack*);
int peek(Stack*);
int pop(Stack*);
void clear(Stack*);

int isEmpty(Stack *stack)
{
	return stack->top < 0;
}

int isFull(Stack *stack)
{
	return stack->top + 1 >= STACK_MAX;
}

int init(Stack *stack)
{
	stack->top = -1;
}

void push(Stack *stack, int n)
{
	if (isFull(stack))
	{
		puts("Stack overflow!");
		return;
	}

	stack->items[++stack->top] = n;
}

void show(Stack* stack)
{
	for (int i = stack->top; i >= 0; i--)
	{
		printf("Stack [%d]: %d\n", stack->top - i, stack->items[i]);
	}
}

int peek(Stack *stack)
{
	if (isEmpty(stack))
	{
		puts("Stack underflow!");
		return -1;
	}

	return stack->items[stack->top];
}

int pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		puts("Stack underflow!");
		return -1;
	}

	return stack->items[stack->top--];
}

void clear(Stack *stack)
{
	stack->top = -1;
}

int main()
{
	// Creating a Stack
	Stack stack;
	init(&stack);

	// Clearing Stack
	push(&stack, 10);
	clear(&stack);

	// Pushing to Stack
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);

	// Showing Stack
	show(&stack);

	return 0;
}
