#include <stdio.h>
#include <stdlib.h>
// 顺序表实现栈
typedef int Datatype;

typedef struct Stack{
	Datatype* _array; // 给动态数组
	size_t _size;// 元素个数
	size_t _capacity;// 容量
}Stack;


void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, Datatype data);

void stackPop(Stack* st);

Datatype stackTop(Stack* st);

size_t stackSize(Stack* st);

int stackEmpty(Stack* st);

void stackDestory(Stack* st);
