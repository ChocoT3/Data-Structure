#define	_CRT_SECURE_NO_WARNINGS
#include"Doubly_Linked_List.h"

void test1()
{
	DLTNode* phead = DListInit();
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushBack(phead, 4);
	DListPrint(phead);

	DListPushFront(phead, 0);
	DListPushFront(phead, -1);
	DListPrint(phead);

	DListPopFront(phead);
	DListPopFront(phead);
	DListPopFront(phead);
	DListPrint(phead);

	DListPopBcak(phead);
	DListPrint(phead);

	DListDestory(phead);
}
int main()
{
	test1();

	return 0;
}


