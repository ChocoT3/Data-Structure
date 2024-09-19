#define	_CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
//��̬�汾
//void SeqListInit(SL* sl)
//{
//	memset(sl->data, 0, sizeof(SQDataType) * MAX_SIZE);
//	sl->size = 0;
//}



//��ʼ��
void SeqListInit(SL* sl)
{
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}
//����
void SeqListDestory(SL* sl)
{
	free(sl->data);//�ڴ��Ƕ�̬��������ģ������Ҫfree
	sl->data = NULL;
	sl->size = 0;
}
//����
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
//ͷ��
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
//β��
void SeqListPushBack(SL* sl, SQDataType val)
{
	SeqListCheckCapacity(sl);
	sl->data[sl->size++] = val;
}
//ͷɾ
void SeqListPopFront(SL* sl)
{
	assert(sl->size > 0);
	for (size_t i = 0; i < sl->size-1; ++i)
	{
		sl->data[i] = sl->data[i + 1];
	}
	sl->size--;
}
//βɾ
void SeqListPopBack(SL* sl)
{
	assert(sl->size > 0);
	sl->size--;
}
//����
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
//����
void SeqListErase(SL* sl, size_t pos)
{
	assert(pos < sl->size);

	for (size_t i = pos; i < sl->size - 1; ++i)
	{
		sl->data[i] = sl->data[i + 1];
	}
	sl->size--;
}
//����
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
//�޸�
void SeqListModity(SL* sl, size_t pos, SQDataType val)
{
	assert(pos < sl->size);
	sl->data[pos] = val;
}
//��ӡ
void SeqListPrint(SL* sl)
{
	assert(sl->size >= 0);
	for (int i = 0; i < sl->size; ++i)
	{
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}








