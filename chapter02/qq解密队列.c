#include<stdio.h>
#define N 101

// ���ö��н���

typedef struct queue{
	int data[N];
	int head;
	int tail;
}Queue;

int main()
{
	Queue q;
	int i;
	// ��ʼ������
	q.head = 1;
	q.tail = 1;
	
	for(i=1;i<10;++i)
	{
		// ����������в���9����
		scanf("%d",&q.data[q.tail]);
		q.tail++; 
	} 
	
	while(q.head<q.tail)  //�����в�Ϊ��ʱ ִ��ѭ������ 
	{
		// ��ӡ���ֲ������ֳ���
		printf("%d ",q.data[q.head]);
		q.head ++;
		
		// �Ƚ����׵�����ӵ���β
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		// �ٽ����׳���
		q.head++; 		
	}
	
	return 0;
} 
