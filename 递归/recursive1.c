#include <stdio.h>

void func(int n)
{
	printf("Level %d: n location %p\n",n,&n);
	if(n < 4)
	{
		func(n+1);
	}
	printf("Level %d: n location %p\n",n,&n);
	
} 
int main(int argc, char *argv[])
{
	func(1);
	return 0;
}
