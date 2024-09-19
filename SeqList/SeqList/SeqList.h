#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
//静态版本
// #define MAX_SiZE 10
// typedef struct SeqList
//{
//	SQDataType data[MAX_SiZE];
//	size_t size;
//}SL;
//动态版本
typedef int SQDataType;

typedef struct SeqList
{
	SQDataType* data;//指向开头
	size_t size;
	size_t capacity;
}SL;

void SeqListInit(SL* sl);
void SeqListDestory(SL* sl);
void SeqListPrint(SL* sl);

void SeqListPushFront(SL* sl,SQDataType val);
void SeqListPushBack(SL* sl, SQDataType val);
void SeqListPopFront(SL* sl);
void SeqListPopBack(SL* sl);
void SeqListInsert(SL* sl,size_t pos, SQDataType val);
void SeqListErase(SL* sl, size_t pos);

int SeqListFind(SL* sl, SQDataType val);
void SeqListModity(SL* sl, size_t pos, SQDataType val);
