#pragma once
#include "stack.h"
#include "Queue.h"
typedef struct spt
{
	Stack s1;
	Stack s2;
}spt;
typedef struct pQueue
{
	Queue q1;
	Queue q2;
}pQueue;

typedef int minDataType;
typedef struct minStack
{
	Stack s;
	Stack min;
}minStack;

#define SSMAX 100
typedef int SSDataType;
typedef struct ShareStack
{
	SSDataType _a[SSMAX];
	int top1;             //第一个栈的栈顶
	int top2;			  //第二个栈的栈顶
}ShareStack;
void ShareStackInit(ShareStack* pss);
void ShareStackPush(ShareStack* pss, SSDataType x, int which); //一个数组两个栈
void ShareStackPop(ShareStack* pss, int which);
SSDataType ShareStackTop(ShareStack* pss, int which);


DataType StackMin(minStack* s);            //找出栈中的最小值
void StackMinPop(minStack* p);
void StackMinPush(minStack* p, minDataType x);

void QueueBy2Stacktest(spt* s);         //两个栈实现一个队列

void StackBy2Queuetest(pQueue* p);		//两个队列实现一个栈
size_t CheckStack(Stack* s, DataType* p, DataType* p1, int len_in, int len_out); //判断出入栈的合法性
void newDestroy(spt* p);
