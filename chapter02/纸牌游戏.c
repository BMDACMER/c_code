#include<stdio.h>
#define MaxSize 1001
#define N 10
#define ElementType int  


/*
* brief:Сè�������⣬  ת��Ϊջ�Ͷ��еĲ�������� 
* input���ֱ������������֣�ÿ������6��  ��С������1~9֮��
* output����ʤһ������������ʣ���ֽ��
* example��
* 	input:	2 4 1 2 5 6
*			3 1 3 5 6 4  
*	output: С��win
*			С�ߵ�ǰ���е����� 5 6 2 3 1 4 6 5
*			���ϵ����� 2 1 3 4
*/

//  ����һ����������ģ��С��С���Ĳ��� 
typedef struct queue{
	ElementType data[MaxSize];
	int head;
	int tail;
}Queue;

//  ����ջ����ģ�����ӵĲ��� 
typedef struct stack{
	ElementType data[N];
	int top;	
}Stack;


int main()
{
	Queue q1,q2;     // q1��q2�ֱ�ģ��С�ߺ�С�����е��� 
	Stack s;         // ģ�������ϵ��� 
	int i,t;
	int book[N];     // ������������ϳ��Ƶ����֣�1~9�� 
	 
	// ��ʼ������q1��q2Ϊ�գ���ʱ�������ﶼû���� 
	q1.head = 1; 	q1.tail = 1;
	q2.head = 1; 	q2.tail = 1;
	// ��ʼ��ջsΪ�գ��ʼ����û����
	s.top= 0;
	// ��ʼ��������ǵ����飬���������Щ������������
	for(i=1;i<=9;i++)
		book[i] = 0;
		 
	// �ȶ��������ƣ��ֱ����С�ߺ�С������
	for(i=1;i<=6;++i)
	{
		scanf("%d",&q1.data[q1.tail++]);   // ����һ����������  		
	} 
	for(i=1;i<=6;++i)
	{
		scanf("%d",&q2.data[q2.tail++]);   // ����һ���������� 	
	}
	
	while(q1.head<q1.tail && q2.head<q2.tail)
	{
		t = q1.data[q1.head];  // С���ȳ��� 
		if(book[t]==0)  //  ��������û������Ϊt����
	  	{
			//С�ߴ���û��Ӯ��
			q1.head++; //С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			s.top++;   // ��ջ 
			s.data[s.top]=t; //�ٰѴ�����Ʒŵ����ϣ�����ջ
			book[t]=1; //������������Ѿ�������Ϊt����  
  		} 
  		else
  		{
		  	//С�ߴ��ֿ���Ӯ��
			q1.head++;//С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			q1.data[q1.tail]=t;//�����ŰѴ�����Ʒŵ������Ƶ�ĩβ
			q1.tail++;
			while(s.data[s.top]!=t) //�����Ͽ���Ӯ�õ������ηŵ������Ƶ�ĩβ
			{
				book[s.data[s.top]]=0;//ȡ�����
				q1.data[q1.tail]=s.data[s.top];//���η����β
				q1.tail++;
				s.top--; //ջ������һ���ƣ�����ջ��Ҫ��1
			}
	  	}
		t=q2.data[q2.head]; //С����һ����
		//�ж�С����ǰ��������Ƿ���Ӯ��
		if(book[t]==0) //��������û������Ϊt����
		{
			//С������û��Ӯ��
			q2.head++; //С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			s.top++;
			s.data[s.top]=t; //�ٰѴ�����Ʒŵ����ϣ�����ջ
			book[t]=1; //������������Ѿ�������Ϊt����
		}
		else
		{
			//С�����ֿ���Ӯ��
			q2.head++;//С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			q2.data[q2.tail]=t;//�����ŰѴ�����Ʒŵ������Ƶ�ĩβ
			q2.tail++;
			while(s.data[s.top]!=t) //�����Ͽ���Ӯ�õ������ηŵ������Ƶ�ĩβ
			{
				book[s.data[s.top]]=0;//ȡ�����
				q2.data[q2.tail]=s.data[s.top];//���η����β
				q2.tail++;
				s.top--;
			}
		}
	}

	if(q2.head==q2.tail)    // ������һ�����е���ȫ������ʱ����Ϸ���������ֻ�ʤ 
	{
		printf("С�߻�ʤ\n");
		printf("С�ߵ�ǰ���е�����");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf(" %d",q1.data[i]);
		if(s.top>0) //�����������������������ϵ���
		{
			printf("\n���ϵ�����");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
			printf("\n");
		}
		else
			printf("\n�����Ѿ�û������");
		}
		else
		{
			printf("С����ʤ\n");
			printf("С����ǰ���е�����");
			for(i=q2.head;i<=q2.tail-1;i++)
				printf(" %d",q2.data[i]);
			if(s.top>0) //�����������������������ϵ���
			{
				printf("\n���ϵ�����");
				for(i=1;i<=s.top;i++)
					printf(" %d",s.data[i]);
				printf("\n");	
			}
			else
				printf("\n�����Ѿ�û������\n");
	}
	return 0;
} 

