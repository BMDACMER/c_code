#include <stdio.h>
#define N 51

// ����������� BFS

int a[N][N];
int book[N][N],n,m,sum;

void dfs(int x,int y,int color)
{
	// ����һ����������
	int next[4][2] ={
		{0,1},   // ������
		{1,0},   // ������
		{0,-1},  // ������
		{-1,0}   // ������  
	}; 
	int k,tx,ty;
	a[x][y] = color;     // ��a[x][y]������ӽ���Ⱦɫ 
	// ö��4������
	for(k=0;k<=3;++k)
	{
		// ������һ��������
		tx = x+next[k][0];
		ty = y+next[k][1];
		// �ж��Ƿ�Խ��
		if(tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//�ж��Ƿ�Ϊ½��
		if(a[tx][ty]>0 && book[tx][ty]==0)
		{
			sum++;
			book[tx][ty]=1;   // �����������߹�
			dfs(tx,ty,color);       // ��ʼ������һ���� 
		}	 
	} 
	return;
} 

int main()
{
	int i,j,num=0;
	scanf("%d%d",&n,&m);
	// �����ͼ
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
			

	// �����Ⱦɫ��ĵ�ͼ
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]>0)
			{
				num--;   // С����ҪȾ����ɫ�ı��
				// ÿ����һ��С��ӦȾ�Բ�ͬ����ɫ�����ÿ��Ҫ-1
				book[i][j]=1;
				dfs(i,j,num); 
			}
		} 
	} 
	
	// ����Ѿ�Ⱦɫ��ĵ�ͼ
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	} 
	
	// ����������Ĵ�С
	printf("\n��%d��С��\n\n",-num);	
		 
	return 0;
}

/*
����������
10 10 
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0 
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0 

*/