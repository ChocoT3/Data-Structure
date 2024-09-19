#define	_CRT_SECURE_NO_WARNINGS
#include"Doubly_Linked_List.h"
DLTNode* BuyDListNode(val)
{
	DLTNode* newNode = (DLTNode*)malloc(sizeof(DLTNode));
	if (newNode == NULL)
	{
		printf("malloc failed!\n");
		exit(-1);
	}
	else
	{
		newNode->data = val;
		newNode->next = newNode->prev = NULL;
		return newNode;
	}
}
DLTNode* DListInit()
{
	DLTNode* phead = BuyDListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;

}
void DListDestory(DLTNode* phead)
{
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur != phead)
	{
		DLTNode* tmp = cur;
		cur = tmp->next;
		free(tmp);
	}
	free(phead);
	phead = NULL;
}
void DListPrint(DLTNode* phead)
{
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void DListPushFront(DLTNode* phead, DLTDataType val)
{
	assert(phead);
	DLTNode* newNode = BuyDListNode(val);
	DLTNode* first = phead->next;
	newNode->next = first;
	first->prev = newNode;
	newNode->prev = phead;
	phead->next = newNode;

}
void DListPushBack(DLTNode* phead, DLTDataType val)
{
	assert(phead);
	DLTNode* newNode = BuyDListNode(val);
	DLTNode* tail = phead->prev;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;

}
void DListPopFront(DLTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	DLTNode* tmp = phead->next->next;
	free(phead->next);
	phead->next = tmp;
	tmp->prev = phead;
}
void DListPopBcak(DLTNode* phead)
{
	assert(phead);
	assert(phead->prev != phead);
	DLTNode* tmp = phead->prev->prev;
	free(phead->prev);
	phead->prev = tmp;
	tmp->next = phead;
}
DLTNode* ListFind(DLTNode* phead, DLTDataType val)
{
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur)
	{
		if (cur->data == val)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
void ListInsert(DLTNode* pos, DLTDataType val)
{
	assert(pos);
	DLTNode* newNode = BuyDListNode(val);
	DLTNode* prev = pos->prev;
	newNode->prev = prev;
	prev->next = newNode;
	newNode->next = pos;
	pos->prev = newNode;
}
void ListErase(DLTNode* pos)
{
	assert(pos);
	DLTNode* prev = pos->prev;
	DLTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}