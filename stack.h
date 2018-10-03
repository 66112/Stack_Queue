#pragma once
#include <stdio.h>
#include <assert.h>
#define MAX_SIZE 100
typedef int DataType;
typedef struct Stack
{
	DataType _array[MAX_SIZE];          //Êý×é
	DataType top;						//Õ»¶¥
	int size;							//ÈÝÁ¿
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps,DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
size_t StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);
void Print(Stack* ps);
