#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool Isempty()
{
	if (top < 0)
		return true;
	else
		return false;
}

bool Isfull()
{
	if (top >= MAX_SIZE - 1)
		return true;
	else
		return false;
}

void push(int value)
{
	if (sfull() == true)
		printf("Stack is full.");
	else
		stack[++top] = value;
}

int pop()
{
	if (Isempty() == true)
		printf("Stack is empty.");
	else
		return stack[top--];
}

int main()
{
	push(3);
	push(5);
	push(12);
	printf("%d", pop());
	printf("%d", pop());
	printf("%d", pop());

	return 0;
}
