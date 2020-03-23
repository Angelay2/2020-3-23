#include "stack.h"

// 栈(受限的线性表)和队列
// 所有的结构底层无非是两种结构(一种是连续的结构, 一种是不连续的结构)
// 1. 栈: 一种特殊的线性表, 其值只允许在固定的一端进行插入和删除元素操作, 进行数据插入和删除操作的一端
// 称为栈顶, 另一端称为栈底. 栈中的数据元素遵守后进先出的原则
// 压栈; 栈的插入操作叫做进栈/压栈/入栈, 入数据在栈顶
// 出栈: 栈的删除操作叫做出栈, 出数据也在栈顶.
// 栈底表示第一个元素放的位置 栈顶表示最后一个元素放的位置

// 栈的实现: 栈的实现一般可以使用数组或者链表, 相对而言数组的结构实现更优一些, 因为数组在尾上插入数据
// 的代价比较小,
// 可以用顺序表的尾插对应栈的入栈, 尾删对应栈的出栈
// 用单链表的头插对应栈的入栈    头删对应栈的出栈 
// 两者对应栈的操作都是O(1),  但是如果两个的性能都差不多的情况下, 优先选择顺序表
// 栈其实是一个更加简单的顺序表


// 栈的初始化
// 相当于开一个n的大小空间
void stackInit(Stack* st, size_t n){
	st->_array = (Datatype*)malloc(sizeof(Datatype) * n);
	st->_size = 0;
	st->_capacity = n;// 当前能存放多少元素 
}

// 入栈
void stackPush(Stack* st, Datatype data){
	// 检查容量
	if (st->_size == st->_capacity){
		// 增加空间和容量, 元素个数不变
		st->_array = (Datatype*)realloc(st->_array, sizeof(Datatype) * 2 * st->_capacity);
		st->_capacity *= 2; 
	}
	// 再进行尾插
	st->_array[st->_size] = data;
}

// 出栈
void stackPop(Stack* st){
	if (st->_size > 0){
		--st->_size;
	}
}

// 获取栈的元素
Datatype stackTop(Stack* st){
	return st->_array[st->_size - 1];
}

// 获取栈的元素个数
size_t stackSize(Stack* st){
	return st->_size;
}

// 栈是否为空
int stackEmpty(Stack* st){
	if (st->_size == 0)
		return 1;
	return 0;
}

// 不给打印了, 因为栈是一个抽象的东西, 要想访问栈空间的元素, 只能使用push->pop->pop的操作
// 栈的销毁(把空间还给系统)
void stackDestory(Stack* st){
	// 如果数组还存在 那就释放数组
	if (st->_array){
		free(st->_array);
		// 空间还给数组后. 数组 容量都为0;
		st->_size = st->_array = 0;
	}
}
