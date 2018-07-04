#include <stdio.h>

int count = 0;        // 定义全局变量 用来记录移动的步数 

void hanoi(int n,char x,char y,char z)
{
	if(n==0)
	{
		/* 什么也不做 */
	}else{
		hanoi(n-1,x,z,y);
		printf("%c->%c\t",x,y);
		count++; 
		hanoi(n-1,z,y,x);
	}
}

int main()
{
	hanoi(3,'A','B','C');
	printf("\n\n");
	printf("总共移动了%d步\n\n",count);
	return 0;
}
