#include "stack.h"
#include "queue.h"

// C++和C的编译规则不同, 导致底层的函数名不同, 最终导致test.app的函数找不到对应的函数指令(函数体),
// 导致连接错误, 所以不能一个文件是.c, 一个文件是.app,会出现错误.
void testStack(){
	Stack st;
	stackInit(&st, 10);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	while (stackEmpty(&st) != 1){
		printf("%d ", stackTop(&st));// 输入1,2,3,4,5  输出5,4,3,2,1
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
		printf("%d ", queueFront(&q));// 打印出1 2 3 4 5 
		queuePop(&q);
	}
	printf("\n");
}

int main(){
	testStack();// 后进先出 5,4,3,2,1
	testQueue();// 先进先出 1,2,3,4,5
	system("pause");
	return 0;
}