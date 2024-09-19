#define	_CRT_SECURE_NO_WARNINGS
#include"Singly_Linked_List.h"

SLTNode* BuySListNode(SLTDataType val)
{
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL)
	{
		printf("malloc failed!\n");
		exit(-1);
	}
	else
	{
		newNode->data = val;
		newNode->next = NULL;
		return newNode;
	}

}

void SListPushFront(PNode* pphead, SLTDataType val)
{
	SLTNode* newNode = BuySListNode(val);
	newNode->next = *pphead;
	*pphead = newNode;
}
void SListPushBack(PNode* pphead, SLTDataType val)
{
	SLTNode* newNode = BuySListNode(val);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
void SListPopFront(PNode* pphead)
{
	SLTNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;

}
void SListPopBack(PNode* pphead)
{
	SLTNode* tail = *pphead;
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pphead = NULL;
	}
	else
	{
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
SLTNode* SListFind(PNode phead, SLTDataType val)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == val)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void SListInsert(PNode* pphead, SLTNode* pos, SLTDataType val)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead, val);
	}
	else
	{
		SLTNode* newNode = BuySListNode(val);
		SLTNode* tmp = *pphead;
		while (tmp->next != pos)
		{
			tmp = tmp->next;
		}
		newNode->next = pos;
		tmp->next = newNode;
	}

}
void SListErase(PNode* pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* tmp = *pphead;
		while (tmp->next != pos)
		{
			tmp = tmp->next;
		}
		tmp->next = pos->next;
		free(pos);
	}

}

void SListPrint(PNode phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
