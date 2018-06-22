#include<stdio.h>
#define N 1001

// 此程序采用桶排序  先去重在排序 

void init(int array[])
{
	int i;
	for(i=0;i<N;++i)
		array[i] = 0;
}

int main()
{
	int array[N];    // 对于数字较小的话 可以采用这种方法      
	int i,t,n,k;
	
	while(scanf("%d",&n)!=EOF)
	{
		
		init(array);
		k=0;
		
		for(i=0;i<n;++i)
		{
			scanf("%d",&t);
			array[t] = 1;
		}
		printf("\n\n--------输出结果为-------\n\n");
		for(i=0;i<N;++i)
		{
			if(array[i]==1)  // 如果数字出现过则打印
			{
				k++;
				printf("%d\t",i);
			}
			
		}
		printf("\n%d\n",k);
		 
	}
	return 0;
}




