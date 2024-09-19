#define	_CRT_SECURE_NO_WARNINGS
#include"Queue.h"

QNode* BuyQueueNode(QDataType val)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	else
	{
		newNode->data = val;
		newNode->next = NULL;
		return newNode;
	}
}
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	while (pq->head)
	{
		QNode* tmp = pq->head;
		pq->head = tmp->next;
		free(tmp);
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType val)
{
	assert(pq);
	QNode* newNode = BuyQueueNode(val);
	if (pq->head == NULL)
	{
		pq->head = newNode;
		pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)//±ÜÃâtailÒ°Ö¸Õë
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* tmp = pq->head;
		pq->head = tmp->next;
		free(tmp);
	}

}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}
size_t QueueSize(Queue* pq)
{
	assert(pq);
	size_t size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

