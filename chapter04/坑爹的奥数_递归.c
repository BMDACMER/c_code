#include <stdio.h>
#include <time.h>

int a[10]={0},i,total=0,book[10]={0};

void dfs(int step)   // step��ʾ����վ�ڵڼ���������ǰ
{
	int i;
	if(step==10)  // ���վ�ڵ�10��������ǰ�����ʾǰ9�������Ѿ��ź��˿���
	{
		if(a[1]*100+a[2]*10+a[3] + a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9])
		{
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		}	
		return;         // ����֮ǰ��һ����������õĵط��� 
	} 
	
	// ��ʱվ�ڵ�step��������ǰ��Ӧ�÷��������أ�
	// ����1��2��3����������n��˳��һһ����
	for(i=1;i<=9;++i)
	{
		// �ж��˿���i�Ƿ�������
		if(book[i]==0) // book[i]Ϊ0��ʾ�˿��ƻ�������
		{
			// ��ʼ����ʹ���˿���i
			a[step] = i;  // ���˿���i���뵽��step��������
			book[i] = 1;
			
			dfs(step+1);
			book[i]=0; 
		} 
	} 
	return;
} 

int main(int argc, char *argv[])
{
	double start,end;
	start = clock();
	dfs(1);    // ����վ��һ��������ǰ 
	end = clock(); 
	printf("\ntotal=%d\n\n",total/2); 
	printf("total cost time:%lfs\n",(end-start)/1000);
	return 0;
}
