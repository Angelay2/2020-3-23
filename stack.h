#include <stdio.h>
#include <stdlib.h>
// ˳���ʵ��ջ
typedef int Datatype;

typedef struct Stack{
	Datatype* _array; // ����̬����
	size_t _size;// Ԫ�ظ���
	size_t _capacity;// ����
}Stack;


void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, Datatype data);

void stackPop(Stack* st);

Datatype stackTop(Stack* st);

size_t stackSize(Stack* st);

int stackEmpty(Stack* st);

void stackDestory(Stack* st);
