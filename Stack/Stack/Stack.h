#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//用动态顺序表实现优
typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	size_t top;
	size_t capacity;
}ST;

void StackInit(ST* stack);
void StackDestory(ST* stack);
void StackPush(ST* stack, STDataType val);
void StackPop(ST* stack);

STDataType StackTop(ST* stack);
size_t StackSize(ST* stack);
bool StackEmpty(ST* stack);