#include<stdio.h>
#define MaxSize 1001
#define N 10
#define ElementType int  


/*
* brief:小猫钓鱼问题，  转化为栈和队列的操作来求解 
* input：分别输入两组数字，每组数字6个  大小限制在1~9之间
* output：获胜一方，和桌子上剩余的纸牌
* example：
* 	input:	2 4 1 2 5 6
*			3 1 3 5 6 4  
*	output: 小哼win
*			小哼当前手中的牌是 5 6 2 3 1 4 6 5
*			桌上的牌是 2 1 3 4
*/

//  定义一个队列用来模拟小哼小哈的操作 
typedef struct queue{
	ElementType data[MaxSize];
	int head;
	int tail;
}Queue;

//  定义栈用来模拟桌子的操作 
typedef struct stack{
	ElementType data[N];
	int top;	
}Stack;


int main()
{
	Queue q1,q2;     // q1，q2分别模拟小哼和小哈手中的牌 
	Stack s;         // 模拟桌子上的牌 
	int i,t;
	int book[N];     // 用来标记桌子上出牌的数字（1~9） 
	 
	// 初始化队列q1和q2为空，此时两人手里都没有牌 
	q1.head = 1; 	q1.tail = 1;
	q2.head = 1; 	q2.tail = 1;
	// 初始化栈s为空，最开始桌上没有牌
	s.top= 0;
	// 初始化用来标记的数组，用来标记哪些牌在桌子上了
	for(i=1;i<=9;i++)
		book[i] = 0;
		 
	// 先读入六张牌，分别放在小哼和小哈手上
	for(i=1;i<=6;++i)
	{
		scanf("%d",&q1.data[q1.tail++]);   // 读入一个数到队列  		
	} 
	for(i=1;i<=6;++i)
	{
		scanf("%d",&q2.data[q2.tail++]);   // 读入一个数到队列 	
	}
	
	while(q1.head<q1.tail && q2.head<q2.tail)
	{
		t = q1.data[q1.head];  // 小哼先出牌 
		if(book[t]==0)  //  表明桌上没有牌面为t的牌
	  	{
			//小哼此轮没有赢牌
			q1.head++; //小哼已经打出一张牌，所以要把打出的牌出队
			s.top++;   // 进栈 
			s.data[s.top]=t; //再把打出的牌放到桌上，即入栈
			book[t]=1; //标记桌上现在已经有牌面为t的牌  
  		} 
  		else
  		{
		  	//小哼此轮可以赢牌
			q1.head++;//小哼已经打出一张牌，所以要把打出的牌出队
			q1.data[q1.tail]=t;//紧接着把打出的牌放到手中牌的末尾
			q1.tail++;
			while(s.data[s.top]!=t) //把桌上可以赢得的牌依次放到手中牌的末尾
			{
				book[s.data[s.top]]=0;//取消标记
				q1.data[q1.tail]=s.data[s.top];//依次放入队尾
				q1.tail++;
				s.top--; //栈中少了一张牌，所以栈顶要减1
			}
	  	}
		t=q2.data[q2.head]; //小哈出一张牌
		//判断小哈当前打出的牌是否能赢牌
		if(book[t]==0) //表明桌上没有牌面为t的牌
		{
			//小哈此轮没有赢牌
			q2.head++; //小哈已经打出一张牌，所以要把打出的牌出队
			s.top++;
			s.data[s.top]=t; //再把打出的牌放到桌上，即入栈
			book[t]=1; //标记桌上现在已经有牌面为t的牌
		}
		else
		{
			//小哈此轮可以赢牌
			q2.head++;//小哈已经打出一张牌，所以要把打出的牌出队
			q2.data[q2.tail]=t;//紧接着把打出的牌放到手中牌的末尾
			q2.tail++;
			while(s.data[s.top]!=t) //把桌上可以赢得的牌依次放到手中牌的末尾
			{
				book[s.data[s.top]]=0;//取消标记
				q2.data[q2.tail]=s.data[s.top];//依次放入队尾
				q2.tail++;
				s.top--;
			}
		}
	}

	if(q2.head==q2.tail)    // 当任意一人手中的牌全部出完时，游戏结束，对手获胜 
	{
		printf("小哼获胜\n");
		printf("小哼当前手中的牌是");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf(" %d",q1.data[i]);
		if(s.top>0) //如果桌上有牌则依次输出桌上的牌
		{
			printf("\n桌上的牌是");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
			printf("\n");
		}
		else
			printf("\n桌上已经没有牌了");
		}
		else
		{
			printf("小哈获胜\n");
			printf("小哈当前手中的牌是");
			for(i=q2.head;i<=q2.tail-1;i++)
				printf(" %d",q2.data[i]);
			if(s.top>0) //如果桌上有牌则依次输出桌上的牌
			{
				printf("\n桌上的牌是");
				for(i=1;i<=s.top;i++)
					printf(" %d",s.data[i]);
				printf("\n");	
			}
			else
				printf("\n桌上已经没有牌了\n");
	}
	return 0;
} 

