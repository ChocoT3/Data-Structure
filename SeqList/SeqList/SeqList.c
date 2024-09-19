#define	_CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
//静态版本
//void SeqListInit(SL* sl)
//{
//	memset(sl->data, 0, sizeof(SQDataType) * MAX_SIZE);
//	sl->size = 0;
//}



//初始化
void SeqListInit(SL* sl)
{
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}
//销毁
void SeqListDestory(SL* sl)
{
	free(sl->data);//内存是动态申请出来的，最后需要free
	sl->data = NULL;
	sl->size = 0;
}
//增容
void SeqListCheckCapacity(SL* sl)
{
	if (sl->size == sl->capacity)
	{
		size_t newCapacity = sl->capacity == 0 ? 4 : sl->capacity * 2;

		SQDataType* temp = (SQDataType*)realloc(sl->data, sizeof(SQDataType) * newCapacity);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			sl->data = temp;
			sl->capacity = newCapacity;
		}
	}
}
//头插
void SeqListPushFront(SL* sl, SQDataType val)
{
	SeqListCheckCapacity(sl);
	for (size_t i = sl->size; i > 0; --i)
	{
		sl->data[i] = sl->data[i - 1];
	}
	sl->data[0] = val;
	sl->size++;
}
//尾插
void SeqListPushBack(SL* sl, SQDataType val)
{
	SeqListCheckCapacity(sl);
	sl->data[sl->size++] = val;
}
//头删
void SeqListPopFront(SL* sl)
{
	assert(sl->size > 0);
	for (size_t i = 0; i < sl->size-1; ++i)
	{
		sl->data[i] = sl->data[i + 1];
	}
	sl->size--;
}
//尾删
void SeqListPopBack(SL* sl)
{
	assert(sl->size > 0);
	sl->size--;
}
//插入
void SeqListInsert(SL* sl, size_t pos, SQDataType val)
{
	assert(pos <= sl->size);
	SeqListCheckCapacity(sl);
	for (size_t i = sl->size; i > pos; --i)
	{
		sl->data[i] = sl->data[i - 1];
	}
	sl->data[pos] = val;
	sl->size++;
}
//销毁
void SeqListErase(SL* sl, size_t pos)
{
	assert(pos < sl->size);

	for (size_t i = pos; i < sl->size - 1; ++i)
	{
		sl->data[i] = sl->data[i + 1];
	}
	sl->size--;
}
//查找
int SeqListFind(SL* sl, SQDataType val)
{
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->data[i] == val)
		{
			return i;
		}
	}
	return -1;
}
//修改
void SeqListModity(SL* sl, size_t pos, SQDataType val)
{
	assert(pos < sl->size);
	sl->data[pos] = val;
}
//打印
void SeqListPrint(SL* sl)
{
	assert(sl->size >= 0);
	for (int i = 0; i < sl->size; ++i)
	{
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}








