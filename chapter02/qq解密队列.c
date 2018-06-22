#include<stdio.h>
#define N 101

// 采用队列解密

typedef struct queue{
	int data[N];
	int head;
	int tail;
}Queue;

int main()
{
	Queue q;
	int i;
	// 初始化队列
	q.head = 1;
	q.tail = 1;
	
	for(i=1;i<10;++i)
	{
		// 依此向队列中插入9个数
		scanf("%d",&q.data[q.tail]);
		q.tail++; 
	} 
	
	while(q.head<q.tail)  //当队列不为空时 执行循环操作 
	{
		// 打印对手并将对手出队
		printf("%d ",q.data[q.head]);
		q.head ++;
		
		// 先将队首的数添加到队尾
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		// 再将队首出队
		q.head++; 		
	}
	
	return 0;
} 
