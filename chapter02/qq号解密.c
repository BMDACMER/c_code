#include<stdio.h>
#define N 101

//  ����qq��

int main()
{
	int qq[N]={0};
	int head,tail,i=1,len=0;
	printf("����������qq�ţ�");
	
	do
	{
		scanf("%d",&qq[i++]);
		len++;
	}while(getchar()!='\n');
		
	head = 1;        // ָ���ͷ  �� ��һ��Ԫ�� 
	tail = len+1;   // ָ���β����һ��Ԫ�� 
	while(head < tail)
	{
		// ��һ��Ԫ��ɾ�� �� ����
		printf("%d\t",qq[head]);
		head ++;    // ��ͷ����
		qq[tail++] = qq[head];  // ��headָ���Ԫ�ط��ڶ�β  ����ʹtail����ƶ�һλ
		head ++;      // ��ͷ�ٴ�����һλ   ��  ���һ��ѭ������ 
	}
	
	return 0;	
} 
