#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
//������ʵ��

//ǰ������
struct BinaruTreeNode;
typedef struct BinaruTreeNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

// ��β��
void QueuePush(Queue* pq, QDataType val);
// ��ͷ��
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
size_t QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);