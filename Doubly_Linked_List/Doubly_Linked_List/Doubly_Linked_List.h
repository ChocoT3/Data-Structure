#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DLTDataType;
typedef struct DListNode
{
	struct DListNode* prev;
	struct DListNode* next;
	DLTDataType data;
}DLTNode;



DLTNode* DListInit();
void DListDestory(DLTNode* phead);
void DListPrint(DLTNode* phead);

void DListPushFront(DLTNode* phead, DLTDataType val);
void DListPushBack(DLTNode* phead, DLTDataType val);
void DListPopFront(DLTNode* phead);
void DListPopBcak(DLTNode* phead);
DLTNode* ListFind(DLTNode* phead, DLTDataType val);
void ListInsert(DLTNode* pos, DLTDataType val);
void ListErase(DLTNode* pos);