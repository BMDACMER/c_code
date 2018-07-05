#include <stdio.h>
#define N 51
#define MaxSize 2501
struct node
{
	int x;   // 横坐标
	int y;   // 纵坐标
	int f;   // 父亲在队列中的编号，本体不要球输出路径，可以不需要f
	int s;   // 步数 
};

int main()
{
	struct node que[MaxSize];   // 因为地图大小为50*50，因此队列扩展不会超过2500个
	int a[N][N]={0}, book[N][N]={0};
	// 定义一个用于表示走的方向的数组
	int next[4][2] = {
		{0,1},      // 向右走
		{1,0},     // 向下走
		{0,-1},     // 向左走
		{-1,0}      // 向上走 
	}; 
	
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	scanf("%d%d%d%d",&startx,&starty,&p,&q);
	
	// 队列初始化
	head = 1;
	tail = 1;
	// 往队列插入迷宫入口坐标
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0;   // 用来标记是否达到目标点，0表示暂未达到，1表示到达
	// 当队列不为空的时候循环
	while(head < tail)
	{
		// 枚举4个方向
		for(k=0;k<=3;++k)
		{
			// 计算下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			// 判断是否越界
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			// 判断是否是障碍物或者已经在路径中
			if(a[tx][ty]==0 && book[tx][ty]==0)
			{
				// 把这个点标记为已经做过
				// 注意bfs每个点只入队一次，所以和dfs不同，不需要将book数组还原
				book[tx][ty] = 1;
				// 插入新的点到队列
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;   // 因为这个点是从head扩展出来的，所以它的父亲是head 本题目不需要求路径，因此本局可忽略 
				que[tail].s = que[head].s + 1; // 步数是父亲的步数+1 
				tail++; 
			}	 
			// 如果到目标点了，停止扩展。任务结束，退出循环
			if(tx==p && ty==q) 
			{
				// 注意下面两句话的位置不能颠倒
				flag = 1;
				break; 
			}
		} 
		if(flag == 1)
			break;
		head++;	
	} 		 
	
	// 打印队列中末尾最后一个点（目标点）的步数
	// 注意tail是指向队列队尾（即最后一位）的下一个位置，所以这需要-1
	printf("\n共需要%d步\n\n",que[tail-1].s); 
	return 0;
} 
