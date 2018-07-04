#include <stdio.h>

void hanoi(int n,char x,char y,char z)
{
	if(n==0)
	{
		/* 什么也不做 */
	}else{
		hanoi(n-1,x,z,y);
		printf("%c->%c\t",x,y);
		hanoi(n-1,z,y,x);
	}
}

int main()
{
	hanoi(3,'A','B','C');
	printf("\n\n");
	return 0;
}
