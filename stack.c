#include "stack.h"

// ջ(���޵����Ա�)�Ͷ���
// ���еĽṹ�ײ��޷������ֽṹ(һ���������Ľṹ, һ���ǲ������Ľṹ)
// 1. ջ: һ����������Ա�, ��ֵֻ�����ڹ̶���һ�˽��в����ɾ��Ԫ�ز���, �������ݲ����ɾ��������һ��
// ��Ϊջ��, ��һ�˳�Ϊջ��. ջ�е�����Ԫ�����غ���ȳ���ԭ��
// ѹջ; ջ�Ĳ������������ջ/ѹջ/��ջ, ��������ջ��
// ��ջ: ջ��ɾ������������ջ, ������Ҳ��ջ��.
// ջ�ױ�ʾ��һ��Ԫ�طŵ�λ�� ջ����ʾ���һ��Ԫ�طŵ�λ��

// ջ��ʵ��: ջ��ʵ��һ�����ʹ�������������, ��Զ�������Ľṹʵ�ָ���һЩ, ��Ϊ������β�ϲ�������
// �Ĵ��۱Ƚ�С,
// ������˳����β���Ӧջ����ջ, βɾ��Ӧջ�ĳ�ջ
// �õ������ͷ���Ӧջ����ջ    ͷɾ��Ӧջ�ĳ�ջ 
// ���߶�Ӧջ�Ĳ�������O(1),  ����������������ܶ����������, ����ѡ��˳���
// ջ��ʵ��һ�����Ӽ򵥵�˳���


// ջ�ĳ�ʼ��
// �൱�ڿ�һ��n�Ĵ�С�ռ�
void stackInit(Stack* st, size_t n){
	st->_array = (Datatype*)malloc(sizeof(Datatype) * n);
	st->_size = 0;
	st->_capacity = n;// ��ǰ�ܴ�Ŷ���Ԫ�� 
}

// ��ջ
void stackPush(Stack* st, Datatype data){
	// �������
	if (st->_size == st->_capacity){
		// ���ӿռ������, Ԫ�ظ�������
		st->_array = (Datatype*)realloc(st->_array, sizeof(Datatype) * 2 * st->_capacity);
		st->_capacity *= 2; 
	}
	// �ٽ���β��
	st->_array[st->_size] = data;
}

// ��ջ
void stackPop(Stack* st){
	if (st->_size > 0){
		--st->_size;
	}
}

// ��ȡջ��Ԫ��
Datatype stackTop(Stack* st){
	return st->_array[st->_size - 1];
}

// ��ȡջ��Ԫ�ظ���
size_t stackSize(Stack* st){
	return st->_size;
}

// ջ�Ƿ�Ϊ��
int stackEmpty(Stack* st){
	if (st->_size == 0)
		return 1;
	return 0;
}

// ������ӡ��, ��Ϊջ��һ������Ķ���, Ҫ�����ջ�ռ��Ԫ��, ֻ��ʹ��push->pop->pop�Ĳ���
// ջ������(�ѿռ仹��ϵͳ)
void stackDestory(Stack* st){
	// ������黹���� �Ǿ��ͷ�����
	if (st->_array){
		free(st->_array);
		// �ռ仹�������. ���� ������Ϊ0;
		st->_size = st->_array = 0;
	}
}
