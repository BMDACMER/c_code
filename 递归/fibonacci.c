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
	printf("쳲��������У�������n��");
	scanf("%d",&n);
	count = fibonacci(n);
	printf("���%d��fibonacci����ֵΪ��%d\n\n",n,count);
	return 0;
}
