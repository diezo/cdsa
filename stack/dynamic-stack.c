#include <stdio.h>
#include <stdlib.h>

#define STACK_DEFAULT_SIZE 100
#define DEBUG 0

typedef struct
{
	int *items;
	int size;
	int top;

	long growns;
	long shrinks;
} Stack;

void init(Stack*);
void resize(Stack*);
void push(Stack*, int);
void show(Stack*);
int peek(Stack*);
int pop(Stack*);
void grow(Stack*);
void shrink(Stack*);
void clear(Stack*);

void init(Stack *stack)
{
	stack->growns = 0;
	stack->shrinks = 0;

	stack->items = (int*) malloc(STACK_DEFAULT_SIZE * sizeof(int));
	stack->size = STACK_DEFAULT_SIZE;
	
	stack->top = -1;
}

void resize(Stack *stack)
{
	if (stack->top + 1 >= stack->size) grow(stack);
	else if (stack->size > STACK_DEFAULT_SIZE && (((stack->top + 1) * 2) < stack->size)) shrink(stack);
}

void grow(Stack *stack)
{
	int *nstack = realloc(stack->items, stack->size * 2 * sizeof(int));

	if (nstack == NULL)
	{
		puts("Failed to grow stack. Stack overflow!");
		return;
	}

	stack->items = nstack;
	stack->size *= 2;

	stack->growns++;

	if (DEBUG) printf("Stack Grown: %d -> %d\n", stack->size / 2, stack->size);
}

void shrink(Stack *stack)
{
	int nsize = stack->size;

	do
	{
		int *nstack = realloc(stack->items, stack->size / 2 * sizeof(int));

		if (nstack == NULL)
		{
			puts("Failed to shrink stack! Ignoring...");
			break;
		}

		stack->items = nstack;
		nsize /= 2;

		stack->shrinks++;

	} while (nsize > STACK_DEFAULT_SIZE && (((stack->top + 1) * 2) < nsize));
	
	if (DEBUG) printf("Stack Shrinked: %d -> %d\n", stack->size, nsize);
	
	stack->size = nsize;
}

void push(Stack *stack, int n)
{
	resize(stack); stack->items[++stack->top] = n;

	if (DEBUG) printf("Pushed: %d; Memory Used: %d/%d\n", n, stack->top + 1, stack->size);
}

void show(Stack *stack)
{
	for (int i = stack->top; i >= 0; i--)
	{
		printf("Stack [%d]: %d\n", stack->top - i, stack->items[i]);
	}
}

int peek(Stack *stack)
{
	return stack->items[stack->top];
}

int pop(Stack *stack)
{
	stack->top--; resize(stack);

	if (DEBUG) printf("Popped: %d; Memory Used: %d/%d\n", stack->items[stack->top], stack->top + 1, stack->size);

	return stack->items[stack->top];
}

void clear(Stack *stack)
{
	if (DEBUG) printf("Stack Cleared.\n");
	
	stack->top = -1; resize(stack);
}

int main()
{
	Stack stack;
	init(&stack);

	for (int i = 1; i <= 50; i++) push(&stack, i);
	for (int i = 1; i <= 30; i++) pop(&stack);

	if (DEBUG)
	{
		printf("\nTotal Growns: %ld\n", stack.growns);
		printf("Total Shrinks: %ld\n", stack.shrinks);

		puts("");
	}

	show(&stack);

	free(stack.items);

	return 0;
}
