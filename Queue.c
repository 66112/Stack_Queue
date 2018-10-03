#include "Queue.h"
void QueueInit(Queue* p)
{
	p->_head = p->_tail = NULL;
}

QueueNode* BuyNode(DataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->data = x;
	newNode->_next = NULL;
	return newNode;
}
void QueuePush(Queue* p, DataType x)
{
	if (p->_head == NULL)
		p->_head = p->_tail = BuyNode(x);
	else
	{
		p->_tail->_next = BuyNode(x);
		p->_tail = p->_tail->_next;
	}
}
QueueNode* QueuePop(Queue* p)
{
	assert(p);
	QueueNode* flag = p->_head;
	p->_head = p->_head->_next;
	return flag;
}
void QueueDestory(Queue* p)
{
	while (p->_head)
	{
		QueueNode* del = p->_head;
		p->_head = p->_head->_next;
		free(del);
	}
}

DataType QueueFront(Queue* p)
{
	assert(p);
	return p->_head->data;
}

DataType QueueBack(Queue* p)
{
	assert(p);
	return p->_tail->data;
}
int QueueEmpty(Queue* p)
{
	assert(p);
	return (p->_head == NULL) ? 0 : 1;
}

void PrintQueue(Queue* p)
{
	assert(p);
	QueueNode* flag = p->_head;
	while (p->_head)
	{
		printf("%d ", p->_head->data);
		p->_head = p->_head->_next;
	}
	p->_head = flag;
}
void test(Queue* p)
{
	QueuePush(p, 1);
	QueuePush(p, 2);
	QueuePush(p, 3);
	QueuePush(p, 4);
	PrintQueue(p);
	printf("\n");
}
void test1(Queue* p, Queue* p1)
{
	while (p->_head)
	{
		while (p->_head != p->_tail)                     //剩一个元素
		{
			QueuePush(p1, QueuePop(p)->data);             //将剩下的一个元素压入p1
		}
		printf("%d ", QueuePop(p)->data);
		while (p1->_head)
		{
			QueuePush(p, QueuePop(p1)->data);             //将p1的元素全部压入到p
		}
	}
	printf("\n");
}
