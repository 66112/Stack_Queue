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
	int top1;             //��һ��ջ��ջ��
	int top2;			  //�ڶ���ջ��ջ��
}ShareStack;
void ShareStackInit(ShareStack* pss);
void ShareStackPush(ShareStack* pss, SSDataType x, int which); //һ����������ջ
void ShareStackPop(ShareStack* pss, int which);
SSDataType ShareStackTop(ShareStack* pss, int which);


DataType StackMin(minStack* s);            //�ҳ�ջ�е���Сֵ
void StackMinPop(minStack* p);
void StackMinPush(minStack* p, minDataType x);

void QueueBy2Stacktest(spt* s);         //����ջʵ��һ������

void StackBy2Queuetest(pQueue* p);		//��������ʵ��һ��ջ
size_t CheckStack(Stack* s, DataType* p, DataType* p1, int len_in, int len_out); //�жϳ���ջ�ĺϷ���
void newDestroy(spt* p);
