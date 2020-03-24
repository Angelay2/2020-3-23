#include "stack.h"
#include "queue.h"

// C++��C�ı������ͬ, ���µײ�ĺ�������ͬ, ���յ���test.app�ĺ����Ҳ�����Ӧ�ĺ���ָ��(������),
// �������Ӵ���, ���Բ���һ���ļ���.c, һ���ļ���.app,����ִ���.
void testStack(){
	Stack st;
	stackInit(&st, 10);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	while (stackEmpty(&st) != 1){
		printf("%d ", stackTop(&st));// ����1,2,3,4,5  ���5,4,3,2,1
		stackPop(&st);
	}
	printf("\n");
}

void testQueue(){
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);
	while (queueEmpty(&q) != 1){
		printf("%d ", queueFront(&q));// ��ӡ��1 2 3 4 5 
		queuePop(&q);
	}
	printf("\n");
}

int main(){
	testStack();// ����ȳ� 5,4,3,2,1
	testQueue();// �Ƚ��ȳ� 1,2,3,4,5
	system("pause");
	return 0;
}