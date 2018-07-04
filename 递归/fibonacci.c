#include <stdio.h>

int fibonacci(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return fibonacci(n-2)+fibonacci(n-1);			
}

int main()
{
	int n,count = 0;
	printf("斐波那契数列，请输入n：");
	scanf("%d",&n);
	count = fibonacci(n);
	printf("则第%d个fibonacci数列值为：%d\n\n",n,count);
	return 0;
}
