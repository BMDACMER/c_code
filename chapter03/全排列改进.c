#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	// ��5���� ����ȫ���� 
	int a[6];  // ���5λ�� 
	int sum,flag[6],i;
	float start,finish;
	start = clock();
	for(a[1]=1;a[1]<=5;++a[1])
		for(a[2]=1;a[2]<=5;++a[2])
			for(a[3]=1;a[3]<=5;++a[3])
				for(a[4]=1;a[4]<=5;++a[4])
					for(a[5]=1;a[5]<=5;++a[5])
					{
						for(i=1;i<=5;++i)  // ��ʼ��flag���� 
							flag[i] = 0; 
						for(i=1;i<=5;++i)    // ���ĳ�������ֹ��ͱ��һ��
							flag[a[i]]=1;
						sum = 0;	
						for(i=1;i<=5;++i)     
							sum += flag[i];    
						// ���ǡ�ó�����5����ͬ�������������������������
						if(sum==5)
						{
							printf("%d%d%d%d%d\n",a[1],a[2],a[3],a[4],a[5]);
						}		
					}
						
	finish = clock();
	printf("�ܺ�ʱ��%.5fs\n",(finish-start)/1000);
	return 0;
}
