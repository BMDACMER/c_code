#include<stdio.h>
#define N 101

// ����ð������  ��������ȥ�� 

int main()
{
	int n,a[N];
	int i,j,len,temp,k;
	
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
			scanf("%d",&a[i]);
		k = 0;
		// bubble sort (From small to big)
		len = n;
		while(--len)
		{
			for(j=0;j<len;++j)
			{
				if(a[j]>a[j+1])
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}	
		}
		
		//  ȥ�� ,�������һ���� 
		printf("\n%d\t",a[0]);
		for(i=1;i<n;++i)
		{
			if(a[i-1]!=a[i])
			{
				printf("%d\t",a[i]);
				k++;
			}
		} 
	
		printf("\n%d\n",k+1); // ���ϵ�һ�������	
	}	
	return 0;
}
