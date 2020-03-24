#pragma once
#include <stdio.h>
// ����βָ��ĵ�����ʵ�ֶ���

typedef int Datatype;
// ������
typedef struct Node{
	struct Node* _next;
	Datatype _data;
}Node;

// �������
typedef struct Queue{
	// ͷβָ��
	Node* _front;
	Node* _rear;
	size_t _size;
}Queue;
// ����
// ��ʼ��
void queueInit(Queue* q);
// ��β����
void queuePush(Queue* q, Datatype data);
// ��ͷɾ��
void queuePop(Queue* q);
// �õ���ͷԪ��
Datatype queueFront(Queue* q);
// �õ���βԪ��
Datatype queueBack(Queue* q);
// �п�
int queueEmpty(Queue* q);
// ������д�С
size_t QueueSize(Queue* q);