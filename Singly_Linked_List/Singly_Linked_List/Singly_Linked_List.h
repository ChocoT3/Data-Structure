#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	struct SListNode* next;
	SLTDataType data;
}SLTNode,*PNode;

void SListPrint(PNode phead);

void SListPushFront(PNode* pphead, SLTDataType val);
void SListPushBack(PNode* pphead, SLTDataType val);
void SListPopFront(PNode* pphead);
void SListPopBack(PNode* pphead);

SLTNode* SListFind(PNode phead, SLTDataType val);

void SListInsert(PNode* pphead, SLTNode* pos, SLTDataType val);
void SListErase(PNode* pphead, SLTNode* pos);