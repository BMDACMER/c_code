#include <stdio.h>
#define N 101
 
int main()
{
	int count[N],i,j,t,n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<N;++i)
			count[i]=0;
			
		for(i=0;i<n;++i)
		{
			scanf("%d",&t);
			count[t]++;
		}	
		
		for(i=0;i<N;++i)
		{
			for(j=1;j<=count[i];++j)
				printf("%d\t",i);
		}
		printf("\n");
	}
	
	return 0;
}
