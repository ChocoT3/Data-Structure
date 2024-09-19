#define	_CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

int main()
{
	SL sl;
	SeqListInit(&sl);
	for (int i = 0; i < 12; i++)
	{
		SeqListPushBack(&sl, i * 10);
	}
	SeqListPrint(&sl);
	SeqListPushFront(&sl, 0);
	SeqListPopFront(&sl);
	SeqListPopBack(&sl);
	SeqListModity(&sl, 0, 100);
	SeqListInsert(&sl, 1, 200);
	SeqListPrint(&sl);
	return 0;
}