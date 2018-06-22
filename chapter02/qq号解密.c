#include<stdio.h>
#define N 101

//  解密qq号

int main()
{
	int qq[N]={0};
	int head,tail,i=1,len=0;
	printf("请输入您的qq号：");
	
	do
	{
		scanf("%d",&qq[i++]);
		len++;
	}while(getchar()!='\n');
		
	head = 1;        // 指向队头  即 第一个元素 
	tail = len+1;   // 指向队尾的下一个元素 
	while(head < tail)
	{
		// 第一个元素删除 即 出队
		printf("%d\t",qq[head]);
		head ++;    // 队头右移
		qq[tail++] = qq[head];  // 将head指向的元素放在队尾  并且使tail向后移动一位
		head ++;      // 队头再次右移一位   ，  完成一次循环操作 
	}
	
	return 0;	
} 
