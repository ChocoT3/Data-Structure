#define	_CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void TestStack()
{
	ST stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);

	printf("%d ", StackTop(&stack));//3
	StackPop(&stack);//1 2
	printf("%d ", StackTop(&stack));//2
	StackPop(&stack);//1

	StackPush(&stack, 4);//1 4
	StackPush(&stack, 5);//1 4 5

	while (!StackEmpty(&stack))
	{
		printf("%d ", StackTop(&stack));//5 4 1
		StackPop(&stack);
	}
	printf("\n");

	StackDestory(&stack);
}

int main()
{
	TestStack();
	return 0;
}