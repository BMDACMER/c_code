#include <stdio.h>

// 阶乘 

void prove(int n)
{
	if(n == 0)
	{
		printf("根据步骤1，得出P(%d)成立。\n",n);
	}else{
		prove(n - 1);
		printf("根据步骤2，可以说“若P(%d)成立，则P(%d)也成立。”\n",n -1,n);
		printf("因此，可以说”P(%d)是成立的“。\n",n);
	}
} 
int main(int argc, char *argv[])
{
	prove(2);
	return 0;
}
