#include <stdio.h>
#define N 51
#define MaxSize 2501
struct node
{
	int x;   // ������
	int y;   // ������
	int f;   // �����ڶ����еı�ţ����岻Ҫ�����·�������Բ���Ҫf
	int s;   // ���� 
};

int main()
{
	struct node que[MaxSize];   // ��Ϊ��ͼ��СΪ50*50����˶�����չ���ᳬ��2500��
	int a[N][N]={0}, book[N][N]={0};
	// ����һ�����ڱ�ʾ�ߵķ��������
	int next[4][2] = {
		{0,1},      // ������
		{1,0},     // ������
		{0,-1},     // ������
		{-1,0}      // ������ 
	}; 
	
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	scanf("%d%d%d%d",&startx,&starty,&p,&q);
	
	// ���г�ʼ��
	head = 1;
	tail = 1;
	// �����в����Թ��������
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0;   // ��������Ƿ�ﵽĿ��㣬0��ʾ��δ�ﵽ��1��ʾ����
	// �����в�Ϊ�յ�ʱ��ѭ��
	while(head < tail)
	{
		// ö��4������
		for(k=0;k<=3;++k)
		{
			// ������һ���������
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			// �ж��Ƿ�Խ��
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;
			// �ж��Ƿ����ϰ�������Ѿ���·����
			if(a[tx][ty]==0 && book[tx][ty]==0)
			{
				// ���������Ϊ�Ѿ�����
				// ע��bfsÿ����ֻ���һ�Σ����Ժ�dfs��ͬ������Ҫ��book���黹ԭ
				book[tx][ty] = 1;
				// �����µĵ㵽����
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;   // ��Ϊ������Ǵ�head��չ�����ģ��������ĸ�����head ����Ŀ����Ҫ��·������˱��ֿɺ��� 
				que[tail].s = que[head].s + 1; // �����Ǹ��׵Ĳ���+1 
				tail++; 
			}	 
			// �����Ŀ����ˣ�ֹͣ��չ������������˳�ѭ��
			if(tx==p && ty==q) 
			{
				// ע���������仰��λ�ò��ܵߵ�
				flag = 1;
				break; 
			}
		} 
		if(flag == 1)
			break;
		head++;	
	} 		 
	
	// ��ӡ������ĩβ���һ���㣨Ŀ��㣩�Ĳ���
	// ע��tail��ָ����ж�β�������һλ������һ��λ�ã���������Ҫ-1
	printf("\n����Ҫ%d��\n\n",que[tail-1].s); 
	return 0;
} 
