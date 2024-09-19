#define	_CRT_SECURE_NO_WARNINGS
#include"Singly_Linked_List.h"

void test1()
{
	PNode phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPushFront(&phead, 0);
	SListPrint(phead);

	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPrint(phead);

	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPrint(phead);

}
void test2()
{
	PNode phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(phead);
}

void test3()
{
	PNode phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	// 想在3的前面插入一个30
	SLTNode* pos = SListFind(phead, 1);
	if (pos)
	{
		SListInsert(&phead, pos, 10);
	}
	SListPrint(phead);

	pos = SListFind(phead, 3);
	if (pos)
	{
		SListInsert(&phead, pos, 30);
	}
	SListPrint(phead);
}

void test4()
{
	PNode phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	SLTNode* pos = SListFind(phead, 1);
	if (pos)
	{
		SListErase(&phead, pos);
	}
	SListPrint(phead);

	pos = SListFind(phead, 4);
	if (pos)
	{
		SListErase(&phead, pos);
	}
	SListPrint(phead);

	pos = SListFind(phead, 3);
	if (pos)
	{
		SListErase(&phead, pos);
	}
	SListPrint(phead);

	pos = SListFind(phead, 2);
	if (pos)
	{
		SListErase(&phead, pos);
	}
	SListPrint(phead);
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}