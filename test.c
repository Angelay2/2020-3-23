#include "stack.h"

void testStack(){
	Stack st;
	stackInit(&st, 10);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	while (stackEmpty(&st) != 1){
		printf("%d ", stackTop(&st));
		stackPop(&st);
	}
	printf("\n");
}

int main(){
	testStack();
	system("pause");
	return 0;
}