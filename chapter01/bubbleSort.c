#include<stdio.h>
#define N 100

int main()
{
	int n,a[N];
	int i,j,len,temp;
	
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		
		// bubble sort (From big to small)
		len = n;
		while(--len)
		{
			for(j=0;j<len;++j)
			{
				if(a[j]<a[j+1])
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}	
		}
		
		for(i=0;i<n;++i)
			printf("%3d\t",a[i]);
		
		printf("\n");	
	}
	
	return 0;
} 
