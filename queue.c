#include "queue.h"
#include <malloc.h>

// 2. ����: ֻ������һ�˽��в������ݲ���, ����һ�˽���ɾ�����ݲ������������Ա�, ���о����Ƚ��ȳ���ԭ��
// �����: ���в��������һ�˳�Ϊ��β,      ������: ����ɾ��������һ��Ϊ��ͷ
// �µ�Ԫ���� ֻ���ڶ�β���в���, ���ܲ��, ��β��, ��ͷ��,
// ��ջ�Ǻ���ȳ�, �������Ǻ�����,�Ƚ��ȳ�

// ����(Ҳ�����Ա�)��ʵ��: 
// ����Ҳ���������������Ľṹʵ��, ʹ������Ľṹʵ�ָ���һ��, 
// ��Ϊ���ʹ������Ľṹ, ������������ͷ�ϳ�����, Ч�ʻ�Ƚϵ�
// ��β���൱��β��, ��ͷ���൱��ͷɾ,
// ˳���: PushBack --> ����: ��� --> O(1)
// ˳���: PopFront --> ����: ���� --> O(N)  �Ӻ���ǰ����, ���û�а취�ı�
// ������: PushBack --> ����: ��� --> O(N)  �������ͨ������һ��βָ��(rear)�����͸��Ӷ� --> O(1)
// ������: PopFront --> ����: ���� --> O(1)  
// ����ѡ��������ʵ�ֶ���

// ��ʼ��
void queueInit(Queue* q){
	// �ն��е�ͷ��βӦ�ö�����NULL,��СΪ0
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
// ��β���� ���
void queuePush(Queue* q, Datatype data){
	// ��Ҫ�ȴ����½��
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	// β��
	// ������ָ����ָ�� ��β���������һ�����
	// ����ǿն���, ������ͷ��βָ�붼ָ��������
	if (q->_front == NULL){// �����һ�����ʱ����
		q->_front = q->_rear = node;
	}
	// ������ǿն���, ԭʼrear��nextָ��node, node��nextָ��NULL
	else{
		q->_rear->_next = node;
		node->_next = NULL;
	}
	// ����β���
	q->_rear = node;
	--q->_size;

}
// ��ͷɾ�� ����

void queuePop(Queue* q){
	// ���жϿ� 
	if (q->_front != NULL){
		Node* next = q->_front->_next;
		// ɾ��ͷ���
		free(q->_front);
		// ����ͷ���
		q->_front = next;
		// ��������ֻ��һ����� ɾ����ͷ���ָ��next(NULL) ����Ҫ���¶�β Ҳָ��NULL
		if (q->_front == NULL)
			q->_rear = NULL;

		--q->_size;
	}
}
// �õ���ͷԪ��
Datatype queueFront(Queue* q){
	return q->_front->_data;
}
// �õ���βԪ��
Datatype queueBack(Queue* q){
	return q->_rear->_data;
}
// �п�
int queueEmpty(Queue* q){
	// �����ж϶�ͷ Ҳ���жϴ�С
	// if(q->_size == 0)
	if (q->_front == NULL)
		return 1;
	return 0;
}
// ������д�С
size_t QueueSize(Queue* q){
	return q->_size;
}