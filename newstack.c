#include "newstack.h"
/////////////////////////////////////////////////////  一个数组两个栈
void ShareStackInit(ShareStack* pss)
{
	assert(pss);
	pss->top1 = 0;
	pss->top2 = 1;
}
void ShareStackPush(ShareStack* pss, SSDataType x, int which)  
{
	assert(pss);
	assert(which == 1 || which == 2);
	if (which == 1&&pss->top1<SSMAX)
	{
		pss->_a[pss->top1] = x;
		pss->top1+=2;
	}
	else 
	{
		pss->_a[pss->top2] = x;
		pss->top2+=2;
	}
}
void ShareStackPop(ShareStack* pss, int which)
{
	assert(pss);
	assert(which == 1 || which == 2);
	if (which == 1&&pss->top2<SSMAX)
	{
		pss->top1-=2;
	}
	else
	{
		pss->top2-=2;
	}

}
SSDataType ShareStackTop(ShareStack* pss, int which)
{
	assert(pss); 
	assert(which == 1 || which == 2);
	if (which == 1)
	{
		return pss->_a[pss->top1-2];
	}
	else 
	{
		return pss->_a[pss->top2 - 2];
	}
}

void ShareStackPrint(ShareStack* pss, int which)
{
	assert(pss);
	assert(which == 1 || which == 2);
	if (which == 1)
	{
		while (pss->top1!=0)
		{
			printf("%d ", ShareStackTop(pss, 1));
			ShareStackPop(pss, 1);
		}
		printf("\n");
	}
	else
	{
		while (pss->top2 != 1)
		{
			printf("%d ", ShareStackTop(pss, 2));
			ShareStackPop(pss, 2);
		}
		printf("\n");
	}
}
void TestShareStack()
{
	ShareStack s;
	ShareStackInit(&s);
	ShareStackPush(&s, 1, 1);
	ShareStackPush(&s, 3, 1);
	ShareStackPush(&s, 5, 1);
	ShareStackPush(&s, 7, 1);
	ShareStackPush(&s, 9, 1);
	ShareStackPrint(&s, 1);
	ShareStackPush(&s, 2, 2);
	ShareStackPush(&s, 4, 2);
	ShareStackPush(&s, 6, 2);
	ShareStackPush(&s, 8, 2);
	ShareStackPush(&s, 10, 2);
	ShareStackPrint(&s, 2);
}
/////////////////////////////////////////////////////////////////////////
size_t CheckStack(Stack* s, DataType* p, DataType* p1, int len_in, int len_out)
{
	assert(p&&p1);
	int i = 0;
	int j = 0;
	for (; i < len_in; i++)
	{
		StackPush(s, p[i]);                    //把入栈的第一个元素先压入辅助栈中
		while (s->_array[s->top] == p1[j])       //比较栈顶元素和出栈的第一个元素是否相等
		{
			StackPop(s);                       //若相等，则出栈
			j++;
		}                                      //若不等，则压入第二个元素
	}
	return s->size>0 ? 0 : 1;
}
void TestCheckStack()
{
	Stack s;
	StackInit(&s);
	DataType stack_in[] = { 1, 2, 3, 4, 5 };            //入栈序列
	DataType stack_out[] = { 4, 3, 5, 2, 1 };			//出栈序列
	int len_in = sizeof(stack_in) / sizeof(stack_in[0]);
	int len_out = sizeof(stack_out) / sizeof(stack_out[0]);
	if (len_in != len_out)
	{
		printf("出栈顺序不合法\n");
		return;
	}
	if (CheckStack(&s, stack_in, stack_out, len_in, len_out))
	{
		printf("出栈顺序合法\n");
	}
	else
	{
		printf("出栈顺序不合法\n");
	}
}

/////////////////////////////////////////////////////////////////////////
//两个栈实现一个队列
void newQueueInit(pQueue* p)
{
	assert(p);
	QueueInit(&p->q1);
	QueueInit(&p->q2);
}

void DestroyQueue(pQueue* p)
{
	assert(p);
	QueueDestory(&p->q1);
	QueueDestory(&p->q2);
}

void StackBy2QueuePush(pQueue* p,DataType x)
{
	assert(p);
	if (p->q1._head == NULL&&p->q2._head == NULL)
		QueuePush(&p->q1, x);
	else if (p->q1._head != NULL)
		QueuePush(&p->q1, x);
	else
		QueuePush(&p->q2, x);
}

void StackBy2QueuePop(pQueue* p)
{
	assert(p);
	if (p->q1._head != NULL)
	{
		while (p->q1._head != p->q1._tail)
		{
			QueuePush(&p->q2,QueueFront(&p->q1));
			QueuePop(&p->q1);
		}
		printf("%d ", p->q1._head->data);
		QueuePop(&p->q1);
	}
	else
	{
		while (p->q2._head != p->q2._tail)
		{
			QueuePush(&p->q1, QueueFront(&p->q2));
			QueuePop(&p->q2);
		}
		printf("%d ", p->q2._head->data);
		QueuePop(&p->q2);
	}
}

void TestStackBy2Queue()
{
	pQueue p;
	newQueueInit(&p);
	StackBy2QueuePush(&p, 1);
	StackBy2QueuePush(&p, 2);
	StackBy2QueuePush(&p, 3);
	StackBy2QueuePush(&p, 4);
	PrintQueue(&p.q1);
	printf("\n");
	StackBy2QueuePop(&p);
	StackBy2QueuePop(&p);
	StackBy2QueuePop(&p);
	StackBy2QueuePop(&p);

	printf("\n");
	//StackBy2Queuetest(&p);		//两个队列实现一个栈
	DestroyQueue(&p);
}
/////////////////////////////////////////////////////////
void newStackInit(spt* p)                //栈的初始化
{
	assert(p);
	StackInit(&p->s1);
	StackInit(&p->s2);
}

void newStackDestroy(spt* p)					//栈的销毁
{
	assert(p);
	StackDestroy(&p->s1);
	StackDestroy(&p->s2);
}

void QueueBy2StackPush(spt* p,DataType x)
{
	assert(p);
	if (StackEmpty(&p->s1) == 0 && StackEmpty(&p->s2) == 0)
	{
		StackPush(&p->s1, x);
	}
	else if (StackEmpty(&p->s1) == 0)
	{
		StackPush(&p->s2, x);
	}
	else
	{
		StackPush(&p->s1, x);
	}
}

void QueueBy2StackPop(spt* p)
{
	assert(p);
	if (StackEmpty(&p->s1) == 0 && StackEmpty(&p->s2) == 0)
	{
		printf("无数据！\n");
	}
	else if (StackEmpty(&p->s2) == 0)
	{
		while (StackEmpty(&p->s1))
		{
			StackPush(&p->s2, StackTop(&p->s1));
			StackPop(&p->s1);
		}
	}
}

void TestQueueBy2Stack()
{
	spt s;
	newStackInit(&s);
	QueueBy2StackPush(&s, 1);
	QueueBy2StackPush(&s, 2); 
	QueueBy2StackPush(&s, 3); 
	QueueBy2StackPush(&s, 4);
	Print(&s.s1);
	printf("\n");
	QueueBy2StackPop(&s);
	Print(&s.s2);
	/*QueueBy2Stacktest(&s);
	printf("\n");
	newStackDestroy(&s);*/
}
/////////////////////////////////////////////////////////////////////
//栈中最小值
void StackMinPush(minStack* p,minDataType x)
{
	assert(p);
	if (StackEmpty(&p->s)==0)
	{
		StackPush(&p->s, x);
		StackPush(&p->min, x);
		return;
	}
	else if (StackTop(&p->s)>=x)
	{
		StackPush(&p->s, x);
		StackPush(&p->min, x);
	}
	else
	{
		StackPush(&p->min, StackTop(&p->min));
	}
}

void StackMinPop(minStack* p)
{
	assert(p);
	StackPop(&p->s);
	StackPop(&p->min);
}
DataType StackMin(minStack* p)                   //栈中最小值
{
	assert(p);
	return StackTop(&p->min);
}

void StackMinInit(minStack* p)
{
	assert(p);
	StackInit(&p->s);
	StackInit(&p->min);
}

void TestStackMin()
{
	minStack s;
	StackMinInit(&s);
	StackMinPush(&s, 1);
	StackMinPush(&s, 2);
	StackMinPush(&s, 1);
	StackMinPush(&s, 1);
	StackMinPush(&s, 0);
	//StackMinPop(&s);
	printf("最小值：%d\n",StackMin(&s));
}
////////////////////////////////////////////////////////////////////////////
int main()
{
	//TestShareStack();				//一个数组实现两个栈
	//TestCheckStack();             //检查出栈顺序是否合法
	//TestStackMin();                 //最小值
	TestQueueBy2Stack();        //两个栈实现一个队列
	//TestStackBy2Queue();        //两个队列实现一个栈
	
	return 0;
}