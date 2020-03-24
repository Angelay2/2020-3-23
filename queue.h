#pragma once
#include <stdio.h>
// 带有尾指针的单链表实现队列

typedef int Datatype;
// 定义结点
typedef struct Node{
	struct Node* _next;
	Datatype _data;
}Node;

// 定义队列
typedef struct Queue{
	// 头尾指针
	Node* _front;
	Node* _rear;
	size_t _size;
}Queue;
// 函数
// 初始化
void queueInit(Queue* q);
// 队尾插入
void queuePush(Queue* q, Datatype data);
// 队头删除
void queuePop(Queue* q);
// 拿到队头元素
Datatype queueFront(Queue* q);
// 拿到队尾元素
Datatype queueBack(Queue* q);
// 判空
int queueEmpty(Queue* q);
// 输出队列大小
size_t QueueSize(Queue* q);