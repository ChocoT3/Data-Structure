#define	_CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void StackInit(ST* stack)
{
	assert(stack);
	stack->data = (STDataType*)malloc(sizeof(STDataType) * 10);
	stack->capacity = 10;
	stack->top = 0;
}
void StackDestory(ST* stack)
{
	assert(stack);
	free(stack->data);
	stack->data = NULL;
	stack->top = stack->capacity = 0;
}
void StackPush(ST* stack, STDataType val)
{
	if (stack->top == stack->capacity)
	{
		STDataType* newPtr = (STDataType*)realloc(stack->data, sizeof(STDataType) * stack->capacity * 2);
		if (newPtr == NULL)
		{
			printf("relloc fail!\n");
			exit(-1);
		}
		else
		{
			stack->data = newPtr;
			stack->capacity *= 2;
		}
	}
	else
	{
		stack->data[stack->top] = val;
		stack->top++;
	}
}
void StackPop(ST* stack)
{
	assert(stack);
	assert(stack->top > 0);
	stack->data[stack->top-1] = 0;
	stack->top--;
}
STDataType StackTop(ST* stack)
{
	assert(stack);
	assert(stack->top > 0);
	return stack->data[stack->top - 1];
}
size_t StackSize(ST* stack)
{
	assert(stack);
	return stack->top;
}
bool StackEmpty(ST* stack)
{
	assert(stack);
	return stack->top == 0;
}
