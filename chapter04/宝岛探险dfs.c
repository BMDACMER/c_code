#include <stdio.h>
#define N 51

// 采用深度搜索 BFS

int a[N][N];
int book[N][N],n,m,sum;

void dfs(int x,int y,int color)
{
	// 定义一个方向数组
	int next[4][2] ={
		{0,1},   // 向右走
		{1,0},   // 向下走
		{0,-1},  // 向左走
		{-1,0}   // 向上走  
	}; 
	int k,tx,ty;
	a[x][y] = color;     // 对a[x][y]这个格子进行染色 
	// 枚举4个方向
	for(k=0;k<=3;++k)
	{
		// 计算下一步的坐标
		tx = x+next[k][0];
		ty = y+next[k][1];
		// 判断是否越界
		if(tx<1 || tx>n || ty<1 || ty>m)
			continue;
		//判断是否为陆地
		if(a[tx][ty]>0 && book[tx][ty]==0)
		{
			sum++;
			book[tx][ty]=1;   // 标记这个点已走过
			dfs(tx,ty,color);       // 开始尝试下一个点 
		}	 
	} 
	return;
} 

int main()
{
	int i,j,startx,starty;
	scanf("%d%d%d%d",&n,&m,&startx,&starty);
	// 读入地图
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
			
	book[startx][starty] = 1;
	sum = 1;
	// 从降落的位置开始
	dfs(startx,starty,-1);
	// 输出已染色后的地图
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	} 
	
	// 最后输出岛屿的大小
	printf("\n岛屿面积为：%d\n\n",sum);	
		 
	return 0;
}

/*
输入样例：
10 10 6 8
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