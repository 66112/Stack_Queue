#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef int DataType;
typedef struct QueueNode
{
	DataType data;
	struct QueueNode* _next;
}QueueNode;
typedef	struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;
void QueueInit(Queue* p);
void QueuePush(Queue* p, DataType x);
QueueNode* QueuePop(Queue* p);
DataType QueueFront(Queue* p);
DataType QueueBack(Queue* p);
void QueueDestory(Queue* p);
int QueueEmpty(Queue* p);
void PrintQueue(Queue* p);


