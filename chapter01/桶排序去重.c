#include<stdio.h>
#define N 1001

// �˳������Ͱ����  ��ȥ�������� 

void init(int array[])
{
	int i;
	for(i=0;i<N;++i)
		array[i] = 0;
}

int main()
{
	int array[N];    // �������ֽ�С�Ļ� ���Բ������ַ���      
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
		printf("\n\n--------������Ϊ-------\n\n");
		for(i=0;i<N;++i)
		{
			if(array[i]==1)  // ������ֳ��ֹ����ӡ
			{
				k++;
				printf("%d\t",i);
			}
			
		}
		printf("\n%d\n",k);
		 
	}
	return 0;
}




