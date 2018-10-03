#include "stack.h"
void StackInit(Stack* ps)
{
	ps->size = 0;
	ps->top = -1;
}

void StackPush(Stack* ps,DataType x)
{
	if (ps->size < MAX_SIZE)
	{
		ps->_array[++ps->top] = x;
		ps->size++;
	}
	else
	{
		printf("Õ»Âú\n");
	}
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->size == 0)
		return;
	ps->top--;
	ps->size--;
}

DataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->top];
}

size_t StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

int StackEmpty(Stack* ps)
{
	return ps->size == 0 ? 0 : 1;    //¿Õ 0  £¬  ·Ç¿Õ  1
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	ps->size = 0;
	ps->top = -1;
}
void Print(Stack* ps)
{
	assert(ps);
	int flag = ps->top;
	while (ps->top>=0)
	{
		printf("%d ", ps->_array[ps->top]);
		ps->top--;
	}
	ps->top = flag;
}


